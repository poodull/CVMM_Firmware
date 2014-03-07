#define DEBOUNCE 10  // button debouncer, how many ms to debounce, 5+ ms is usually plenty

// here is where we define the buttons that we'll debounce.  Split into 7 bit blocks
const uint8_t BUTTONS[] = {
    PI_OUTH,    PI_TROR,    PI_TROMR,   PI_TROM,    PI_TROML,   PI_TROL,    PI_SLANE,
    PI_REOS,    PI_LEOS,    PI_OPTLDRN, PI_OPTLRET, PI_LSLING,  PI_RSLING,  PI_OPTRRET,
    PI_OPTRDRN, PI_DRACD,   PI_DRACR,   PI_DRACA,   PI_DRACC,   PI_DRACU,   PI_DRACL,
    PI_DRACA2,  PI_VUK,     PI_DROPA,   PI_DROPB,   PI_DROPC,   PI_BELMB,   PI_BELME,
    PI_BELML,   PI_BELMM,   PI_BELMO,   PI_BELMN,   PI_BELMT,   PI_ORBLO,   PI_RAMPEX,
    PI_ORBLI,   PI_BOSS,    PI_CENTEX,  PI_CENTSC,  PI_ORBRI,   PI_CANDLE,  PI_RIGHTEX,
    PI_ORBRO,   PI_ORBTO,   PI_LPOP,    PI_TPOP,    PI_RPOP,    PI_LFLIP,   PI_RFLIP};

//Lookup table from button index to solenoid index for immediate firing
const uint8_t  BUTTON_SOLIMMED[] = {
    UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,
    SOL03,      SOL01,      SOL06,      UNDEF,      SOL23,      SOL24,      UNDEF,
    UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,
    UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,
    UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,
    UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,      UNDEF,
    UNDEF,      UNDEF,      SOL21,      SOL20,      SOL22,      SOL00,      SOL02};  

// This handy macro lets us determine how big the array up above is, by checking the size
#define NUMBUTTONS sizeof(BUTTONS)

// we will track if a button is just pressed, just released, or 'currently pressed' 
volatile uint8_t    _btn_pressed[NUMBUTTONS],       //the overall current state of a switch (on or off)
                    _btn_justpressed[NUMBUTTONS],   //True if the button has just been pressed
                    _btn_justreleased[NUMBUTTONS];  //True if the button has just been released

// an array of longs(millis) of how long a button has been pressed.  Used for timeouts
volatile uint64_t _btn_onSince[NUMBUTTONS];

// An array of bytes where each bit represents a single switch's state
uint8_t _switchArrayOutput[8]; // NUMBUTTONS / 7 + remainder = 8 bytes

//Flag to post the new switch states to Serial
static bool _isSwitchesDirty = true;

//Initialization of pin modes. This happens once.
void initializeSwitches()
{
    DebugPrint("Button checker with ");
    DebugPrintInt(NUMBUTTONS);
    DebugPrintLn(" buttons."); 
    
    sanityTest();

    for(uint8_t index = 0; index < NUMBUTTONS; index++)
    {
        pinMode(BUTTONS[index], INPUT_PULLUP); //this sets the pin to input mode
        //digitalWrite(BUTTONS[index], HIGH); //this turns on the resistor
    }

    //pinMode(PO_STATUS, OUTPUT); //PIN13 (PO_STATUS) for arduino is the standard LED output on the board.
  
    initalizeSwitchArray();
    DebugPrintLn("Switch Initialization Completed.");
}

//Checks to see if any buttons are assigned to duplicate pins.
//This might be normal in the future, but for now it is a nono.
void sanityTest()
{
    for(int index = 0; index < NUMBUTTONS; index++)
    {
        for(int inner = 0; inner < NUMBUTTONS; inner++)
        {
            if (index == inner)
            {
                continue;
            }
            else
            {
                if (BUTTONS[index] == BUTTONS[inner])
                {
                    DebugPrint("ERROR! buttons ");//this is a horrible way to output data.
                    DebugPrintByte(index); 
                    DebugPrint(" and ");
                    DebugPrintByte(inner); 
                    DebugPrint(" BOTH equal ");
                    DebugPrintLnByte(BUTTONS[index]);
                }
            }
        }
    }
    DebugPrintLn("Switch Sanity Check Completed.");
}


//Initialize the switch states to a null state.
//This is outside of initSwitches because this might be called later to 'soft reset'
void initalizeSwitchArray()
{
    for(uint8_t index = 0; index < NUMBUTTONS; index++)
    {
        _btn_justpressed[index] = 0;
        _btn_justreleased[index] = 0;
        _btn_pressed[index] = 0;
        _btn_onSince[index] = 0;
    }
}

//Iterates through all switches and modifies their state array
//This is called by the Interrupt and uses the DEBOUNCE const 
//to make sure we get rid of jitter.
//max32/due calls this directly.
void check_switches()
{
    static uint8_t previousstate[NUMBUTTONS];
    static uint8_t currentstate[NUMBUTTONS];
    static uint64_t lasttime;
    static uint64_t timer;
    uint8_t index;

    if (millis() < lasttime) 
    {
        // millis wrapped around to 0, lets just reset lasttime to now and try again next timer hit
        lasttime = millis();
        // this will effectively make the switch handler wait 2x DEBOUNCE, though I doubt it will be an issue.
        // if it is, we could set lasttime = 0 instead.
    }

    if ((lasttime + DEBOUNCE) > millis()) 
    {
        return; // not enough time has passed to debounce
    }

    // ok we have waited DEBOUNCE milliseconds, lets reset the timer
    lasttime = millis();
    timer = millis();
    //for every button in the switch array...
    for (index = 0; index < NUMBUTTONS; index++) 
    {
        currentstate[index] = digitalRead(BUTTONS[index]);   // read the button
         
        ////Serial.print(index, DEC);
        ////Serial.print(": cstate=");
        ////Serial.print(currentstate[index], DEC);
        ////Serial.print(", pstate=");
        ////Serial.print(previousstate[index], DEC);
        ////Serial.print(", press=");

        if (currentstate[index] == previousstate[index])    //if still on or still off since debounce
        {
            if ((_btn_pressed[index] == LOW) && (currentstate[index] == LOW))  //it's on for 2 iterations, so now ON
            {
                ////Serial.println();
                ////Serial.print(buttons[index], DEC);
                ////Serial.print(" = ");
                ////Serial.println(currentstate[index], DEC);

                // just pressed
                _btn_justpressed[index] = 1;        //mark it just pressed
                _btn_justreleased[index] = 0;       //unmark it just released
                _btn_onSince[index] = millis();     //note when it was turned on
                
                //TODO: link button presses to immediate solenoid action like flippers and pops and sling
                if (BUTTON_SOLIMMED[index] != UNDEF)
                  solenoidFireImmediate(BUTTON_SOLIMMED[index], true);
            }
            else if ((_btn_pressed[index] == HIGH) && (currentstate[index] == HIGH)) //it's off for 2 iterations, so now OFF
            {
                ////Serial.println();
                ////Serial.print(buttons[index], DEC);
                ////Serial.print(" = ");
                ////Serial.print(currentstate[index], DEC);
                ////Serial.print(" was on for ");
                ////Serial.println(millis() - _btn_onSince[index], DEC);

                // just released
                _btn_justpressed[index] = 0;        //unmark it just pressed
                _btn_justreleased[index] = 1;       //mark it just released
                _btn_onSince[index] = 0;            //reset the 'on since' timer to 0                
                
                //TODO: link button presses to immediate solenoid action like flippers and pops and sling
                if (BUTTON_SOLIMMED[index] != UNDEF)
                  solenoidFireImmediate(BUTTON_SOLIMMED[index], false);
            }
            _btn_pressed[index] = !currentstate[index];  // remember, digital HIGH means NOT pressed
        }
        ////Serial.println(pressed[index], DEC);
        previousstate[index] = currentstate[index];   // keep a running tally of the buttons
    }    
    ////Serial.println(timer - millis(), DEC);
    ////Serial.print(".");

    _isSwitchesDirty = true; //we need to publish the new switch values.
    //this is set to true even though no button changes might have happened at all.
}

bool writeSwitchStatus() //does this belong in zSerial?
{
    if (!_isSwitchesDirty)
        return false;
    if (!_spewStatus)
    {
        _isSwitchesDirty = false;
        return true;
    }
    if (_spewDebug)
    {
        DebugPrint(">");
        for(uint8_t index = 0; index < NUMBUTTONS; index++)
        {
            if (_btn_pressed[index] == 0)
                DebugPrintByte(0);
            else
                DebugPrintByte(1);
        }
        DebugPrintLn(".");
    }
    else
    {
        Serial.write("$"); //This starts the switch status spew

        //convert our array of 0s and 1s to a smaller byte array to serialize
        arrayToByteArray(_btn_pressed, NUMBUTTONS, _switchArrayOutput);

        //print out the byte array.
        for(uint8_t block = 0; block < sizeof(_switchArrayOutput); block++)
        {
            Serial.write(_switchArrayOutput[block]); //not much faster
        }

        Serial.write("."); //This ends the switch status spew
    }
    _isSwitchesDirty = false;
    return true;
}

