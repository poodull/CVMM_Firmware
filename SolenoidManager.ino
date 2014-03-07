//#define MEGA true
//#define MAX32 true

#if true //solenoid on/off/delay arrays
//Defines a delay before a solenoid is fired
static uint32_t _sol_delayOn[] = 
{  
    //' SOLENOID BANK 0 is 50v
    0,      //' sol0.0 is the left power
    0,      //' sol0.1 is the left hold
    0,      //' sol0.2 is the right power
    0,      //' sol0.3 is the right hold
    0,      //' sol0.4 is the trough eject
    0,      //' sol0.5 is the autoplunger
    200,    //' sol0.6 is the shield kickback
    0,       //' sol0.7 is the vuk
    //' SOLENOID BANK 1 is 50v
    0,      //' sol1.0 is the drop target a activate
    0,      //' sol1.1 is the drop target b activate
    0,      //' sol1.2 is the drop target c activate
    0,      //' sol1.3 is the 
    0,      //' sol1.4 is the 
    0,      //' sol1.5 is the 
    0,      //' sol1.6 is the 
    0,      //' sol1.7 is the    
    //' SOLENOID BANK 2 is 20v
    0,      //' sol2.0 is the top pop
    0,      //' sol2.1 is the left pop
    0,      //' sol2.2 is the right pop
    0,      //' sol2.3 is the left sling
    0,      //' sol2.4 is the right sling
    0,      //' sol2.5 is the drop target a reset
    0,      //' sol2.6 is the drop target b reset
    0,      //' sol2.7 is the drop target c reset
    //' SOLENOID BANK 3 is 20v
    0,      //' sol3.0 is the f1 flasher
    0,      //' sol3.1 is the f2 flasher
    0,      //' sol3.2 is the f3 flasher
    0,      //' sol3.3 is the f4 flasher
    0,      //' sol3.4 is the f5 flasher
    0,      //' sol3.5 is the f6 flasher
    0,      //' sol3.6 is the f7 flasher
    0,      //' sol3.7 is the f8 flasher
};
// Defines the max time a solenoid can be on.  0 is infinite.
static uint32_t _sol_maxOn[] =  
{ 
    //' SOLENOID BANK 0 is 50v
    40,     //' sol0.0 is the left power
    0,      //' sol0.1 is the left hold
    40,     //' sol0.2 is the right power
    0,      //' sol0.3 is the right hold
    40,      //' sol0.4 is the trough eject
    40,      //' sol0.5 is the autoplunger
    500,    //' sol0.6 is the shield kickback
    0,       //' sol0.7 is the vuk
    //' SOLENOID BANK 1 is 50v
    0,      //' sol1.0 is the drop target a activate
    0,      //' sol1.1 is the drop target b activate
    0,      //' sol1.2 is the drop target c activate
    0,      //' sol1.3 is the 
    0,      //' sol1.4 is the 
    0,      //' sol1.5 is the 
    0,      //' sol1.6 is the 
    0,      //' sol1.7 is the    
    //' SOLENOID BANK 2 is 20v
    40,      //' sol2.0 is the top pop
    40,      //' sol2.1 is the left pop
    40,      //' sol2.2 is the right pop
    0,      //' sol2.3 is the left sling
    0,      //' sol2.4 is the right sling
    0,      //' sol2.5 is the drop target a reset
    0,      //' sol2.6 is the drop target b reset
    0,      //' sol2.7 is the drop target c reset
    //' SOLENOID BANK 3 is 20v
    0,      //' sol3.0 is the f1 flasher
    0,      //' sol3.1 is the f2 flasher
    0,      //' sol3.2 is the f3 flasher
    0,      //' sol3.3 is the f4 flasher
    0,      //' sol3.4 is the f5 flasher
    0,      //' sol3.5 is the f6 flasher
    0,      //' sol3.6 is the f7 flasher
    0,      //' sol3.7 is the f8 flasher
};
// Defines the minimum time a solenoid can be on.  
static uint32_t _sol_minOn[] =  
{  
    //' SOLENOID BANK 0 is 50v
    0,      //' sol0.0 is the left power
    0,      //' sol0.1 is the left hold
    0,      //' sol0.2 is the right power
    0,      //' sol0.3 is the right hold
    0,      //' sol0.4 is the trough eject
    0,      //' sol0.5 is the autoplunger
    400,    //' sol0.6 is the shield kickback
    0,      //' sol0.7 is the vuk
    //' SOLENOID BANK 1 is 50v
    0,      //' sol1.0 is the drop target a activate
    0,      //' sol1.1 is the drop target b activate
    0,      //' sol1.2 is the drop target c activate
    0,      //' sol1.3 is the 
    0,      //' sol1.4 is the 
    0,      //' sol1.5 is the 
    0,      //' sol1.6 is the 
    0,      //' sol1.7 is the    
    //' SOLENOID BANK 2 is 20v
    0,      //' sol2.0 is the top pop
    0,      //' sol2.1 is the left pop
    0,      //' sol2.2 is the right pop
    0,      //' sol2.3 is the left sling
    0,      //' sol2.4 is the right sling
    0,      //' sol2.5 is the drop target a reset
    0,      //' sol2.6 is the drop target b reset
    0,      //' sol2.7 is the drop target c reset
    //' SOLENOID BANK 3 is 20v
    0,      //' sol3.0 is the f1 flasher
    0,      //' sol3.1 is the f2 flasher
    0,      //' sol3.2 is the f3 flasher
    0,      //' sol3.3 is the f4 flasher
    0,      //' sol3.4 is the f5 flasher
    0,      //' sol3.5 is the f6 flasher
    0,      //' sol3.6 is the f7 flasher
    0,      //' sol3.7 is the f8 flasher
};

//Defines the minimum time a solenoid should be off before fired again.
static uint32_t _sol_minOff[] =  
{  
    //' SOLENOID BANK 0 is 50v
    20,      //' sol0.0 is the left power
    20,      //' sol0.1 is the left hold
    20,      //' sol0.2 is the right power
    20,      //' sol0.3 is the right hold
    20,      //' sol0.4 is the trough eject
    20,      //' sol0.5 is the autoplunger
    20,    //' sol0.6 is the shield kickback
    20,      //' sol0.7 is the vuk
    //' SOLENOID BANK 1 is 50v
    20,      //' sol1.0 is the drop target a activate
    20,      //' sol1.1 is the drop target b activate
    20,      //' sol1.2 is the drop target c activate
    20,      //' sol1.3 is the 
    20,      //' sol1.4 is the 
    20,      //' sol1.5 is the 
    20,      //' sol1.6 is the 
    20,      //' sol1.7 is the    
    //' SOLENOID BANK 2 is 20v
    20,      //' sol2.0 is the top pop
    20,      //' sol2.1 is the left pop
    20,      //' sol2.2 is the right pop
    20,      //' sol2.3 is the left sling
    20,      //' sol2.4 is the right sling
    20,      //' sol2.5 is the drop target a reset
    20,      //' sol2.6 is the drop target b reset
    20,      //' sol2.7 is the drop target c reset
    //' SOLENOID BANK 3 is 20v
    20,      //' sol3.0 is the f1 flasher
    20,      //' sol3.1 is the f2 flasher
    20,      //' sol3.2 is the f3 flasher
    20,      //' sol3.3 is the f4 flasher
    20,      //' sol3.4 is the f5 flasher
    20,      //' sol3.5 is the f6 flasher
    20,      //' sol3.6 is the f7 flasher
    20,      //' sol3.7 is the f8 flasher
};
//' SOLENOID BANK 0 is 50v
const uint8_t SOL00 = 0; //' sol0.0 is the left power //chained to sol0.1
const uint8_t SOL01 = 1; //' sol0.1 is the left hold
const uint8_t SOL02 = 2; //' sol0.2 is the right power //chained to sol0.3
const uint8_t SOL03 = 3; //' sol0.3 is the right hold
const uint8_t SOL04 = 4; //' sol0.4 is the trough eject
const uint8_t SOL05 = 5; //' sol0.5 is the autoplunger
const uint8_t SOL06 = 6; //' sol0.6 is the shield kickback
const uint8_t SOL07 = 7; //' sol0.7 is the vuk
//' SOLENOID BANK 1 is 50v
const uint8_t SOL10 = 8; //' sol1.0 is the drop target a activate
const uint8_t SOL11 = 9; //' sol1.1 is the drop target b activate
const uint8_t SOL12 = 10; //' sol1.2 is the drop target c activate
const uint8_t SOL13 = 11; //' sol1.3 is the 
const uint8_t SOL14 = 12; //' sol1.4 is the 
const uint8_t SOL15 = 13; //' sol1.5 is the 
const uint8_t SOL16 = 14; //' sol1.6 is the 
const uint8_t SOL17 = 15; //' sol1.7 is the 
//' SOLENOID BANK 2 is 20v
const uint8_t SOL20 = 16; //' sol2.0 is the top pop
const uint8_t SOL21 = 17; //' sol2.1 is the left pop
const uint8_t SOL22 = 18; //' sol2.2 is the right pop
const uint8_t SOL23 = 19; //' sol2.3 is the left sling
const uint8_t SOL24 = 20; //' sol2.4 is the right sling
const uint8_t SOL25 = 21; //' sol2.5 is the drop target a reset
const uint8_t SOL26 = 22; //' sol2.6 is the drop target b reset
const uint8_t SOL27 = 23; //' sol2.7 is the drop target c reset
//' SOLENOID BANK 3 is 20v
const uint8_t SOL30 = 24; //' sol3.0 is the f1 flasher
const uint8_t SOL31 = 25; //' sol3.1 is the f2 flasher
const uint8_t SOL32 = 26; //' sol3.2 is the f3 flasher
const uint8_t SOL33 = 27; //' sol3.3 is the f4 flasher
const uint8_t SOL34 = 28; //' sol3.4 is the f5 flasher
const uint8_t SOL35 = 29; //' sol3.5 is the f6 flasher
const uint8_t SOL36 = 30; //' sol3.6 is the f7 flasher
const uint8_t SOL37 = 31; //' sol3.7 is the f8 flasher
const uint8_t UNDEF = 254; //undefined const

static uint8_t _sol_chainedPointer[] = 
{ 
    //' SOLENOID BANK 0 is 50v
    SOL01,      //' sol0.0 is the left power
    UNDEF,      //' sol0.1 is the left hold
    SOL03,      //' sol0.2 is the right power
    UNDEF,      //' sol0.3 is the right hold
    UNDEF,      //' sol0.4 is the trough eject
    UNDEF,      //' sol0.5 is the autoplunger
    UNDEF,    //' sol0.6 is the shield kickback
    UNDEF,      //' sol0.7 is the vuk
    //' SOLENOID BANK 1 is 50v
    UNDEF,      //' sol1.0 is the drop target a activate
    UNDEF,      //' sol1.1 is the drop target b activate
    UNDEF,      //' sol1.2 is the drop target c activate
    UNDEF,      //' sol1.3 is the 
    UNDEF,      //' sol1.4 is the 
    UNDEF,      //' sol1.5 is the 
    UNDEF,      //' sol1.6 is the 
    UNDEF,      //' sol1.7 is the    
    //' SOLENOID BANK 2 is 20v
    UNDEF,      //' sol2.0 is the top pop
    UNDEF,      //' sol2.1 is the left pop
    UNDEF,      //' sol2.2 is the right pop
    UNDEF,      //' sol2.3 is the left sling
    UNDEF,      //' sol2.4 is the right sling
    UNDEF,      //' sol2.5 is the drop target a reset
    UNDEF,      //' sol2.6 is the drop target b reset
    UNDEF,      //' sol2.7 is the drop target c reset
    //' SOLENOID BANK 3 is 20v
    UNDEF,      //' sol3.0 is the f1 flasher
    UNDEF,      //' sol3.1 is the f2 flasher
    UNDEF,      //' sol3.2 is the f3 flasher
    UNDEF,      //' sol3.3 is the f4 flasher
    UNDEF,      //' sol3.4 is the f5 flasher
    UNDEF,      //' sol3.5 is the f6 flasher
    UNDEF,      //' sol3.6 is the f7 flasher
    UNDEF,      //' sol3.7 is the f8 flasher
};
#endif //solenoid on/off/delay/index/chain arrays


//The current known state of the solenoids by a timestamp of when they were fired
static volatile uint64_t _sol_currentState[32];

//The last know timestamp of the solenoids being ON.
static volatile uint64_t _sol_lastOn[32]; 

//The current known state of the solenoids by a timestamp of when they were fired
static bool _sol_isDisabled[32];

void initializeDriverBoard()
{
    //Add here to clear the board for safety
    digitalWrite(PO_SOLEN, HIGH);  //Set Enable HIGH to disable output drives

    digitalWrite(PO_SOLBK0, LOW); // idle data latch control
    digitalWrite(PO_SOLBK1, LOW); // idle data latch control
    digitalWrite(PO_SOLBK2, LOW); // idle data latch control
    digitalWrite(PO_SOLBK3, LOW); // idle data latch control

    digitalWrite(PO_SOLD0, LOW); //clear drives for S1, S9, S17, S25
    digitalWrite(PO_SOLD1, LOW); // clear drives ....
    digitalWrite(PO_SOLD2, LOW);
    digitalWrite(PO_SOLD3, LOW);
    digitalWrite(PO_SOLD4, LOW);
    digitalWrite(PO_SOLD5, LOW);
    digitalWrite(PO_SOLD6, LOW);
    digitalWrite(PO_SOLD7, LOW);

    digitalWrite(PO_SOLBK0, HIGH); // latch data into bank 0
    delay(1);         // delay is not really necessary here but doing it for fun.
    digitalWrite(PO_SOLBK0, LOW); // idle data bank control


    digitalWrite(PO_SOLBK1, HIGH); // latch data into bank 1
    delay(1);
    digitalWrite(PO_SOLBK1, LOW); // idle data bank control


    digitalWrite(PO_SOLBK2, HIGH); // latch data into bank 2
    delay(1);
    digitalWrite(PO_SOLBK2, LOW); // idle data bank control


    digitalWrite(PO_SOLBK3, HIGH); // latch data into bank 3
    delay(1);
    digitalWrite(PO_SOLBK3, LOW); // idle data bank control

    // the board should now be "clear" all drives set to off and disabled
}

void EnableSolenoids(bool enable)
{
  digitalWrite(PO_SOLEN, enable == LOW); //LOW == FALSE == ON
}

void EnableSolenoids(uint8_t solenoidId, bool enable)
{
  //digitalWrite(PO_SOLEN, enable == LOW); //LOW == FALSE == ON
}

void solenoidFireImmediate(uint32_t solenoidId, bool state)
{
    //byte bankId = solenoidId / 8; //div gives us the bank [0..3]
    //byte channelId = solenoidId % 8; //modulus gives the remainder [0..7]
  
    ////Serial.print("Firing Bank: ");
    ////Serial.print(bankId, DEC);
    ////Serial.print(" Channel: ");
    ////Serial.println(channelId, DEC);

    if (_sol_currentState[solenoidId] == 0) //not currently on, only have to worry if we can't re-flash so soon. Or part of a chain.
    {
        if (state) //caller wants it on
        {
            if (_sol_chainedPointer[solenoidId] != UNDEF //has a chain
            && _sol_currentState[_sol_chainedPointer[solenoidId]] != 0) //AND chain is ON
            {
                //This solenoid was turned off, but the chained solenoid is on, so we'll stay off.
            }
            else if (_sol_lastOn[solenoidId] != 0 //last time it was on is regestered
            && millis() - _sol_lastOn[solenoidId] <= _sol_minOff[solenoidId]) //AND too soon
            {
                //wants to be turned on too soon.  should mark it to be turned on, but later.
                // or ignore, and force the caller to retry.
                DebugPrint("Cant turn on solenoid "); DebugPrintInt(solenoidId);  //DEBUG
                DebugPrint(" so soon.  Skipping.  Time on ms: "); DebugPrintLnInt(uint32_t(millis() - _sol_lastOn[solenoidId])); //DEBUG
            }
            else
            {
                _sol_currentState[solenoidId] = millis(); //mark the time we turned this solenoid on
                DebugPrint("Turning ON solenoidId "); DebugPrintLnInt(solenoidId);  //DEBUG
            }
        }
        else 
        {
            _sol_currentState[solenoidId] = 0; //off is easy.  just turn it off.
            DebugPrint("Solenoid is already OFF: "); DebugPrintLnInt(solenoidId);  //DEBUG
        }
    }
    else //currently on, have to worry about timeouts
    {
        if (state) //caller wants it on, still or again?
        {
            if (_sol_maxOn[solenoidId] != 0 //has a maximum on value
            && millis() - _sol_currentState[solenoidId] >= _sol_maxOn[solenoidId]) //AND on too long.
            {
                //  turn it off.
                _sol_currentState[solenoidId] = 0;
                _sol_lastOn[solenoidId] = millis();
                DebugPrint("ERR: Solenoid Overload.  Not turning solenoid on. "); //not sure this should just reset the timer or kill it.  //DEBUG
                DebugPrintLnInt(solenoidId);  //DEBUG
            }
            //else //solenoid is on, but not over the max timeout.  do nothing
        }
        else //caller wants it off 
        {
            DebugPrint("Solenoid OFF: "); DebugPrintLnInt(solenoidId);  //DEBUG
            _sol_currentState[solenoidId] = 0;
            _sol_lastOn[solenoidId] = millis();
        }
    }
    //check to see if this is part of a chain, and if that 2nd chain is on or off
    if (_sol_chainedPointer[solenoidId] != UNDEF)
    {
        DebugPrint("Chaining "); DebugPrintLnByte(_sol_chainedPointer[solenoidId]);
        //we have a chained solenoid.  We'll use the same logic to fire it with recursion
        solenoidFireImmediate(_sol_chainedPointer[solenoidId], state); //recursive call to chain        
    }
}

/// <summary>
/// Write a band of data for 8 solenoids to fire now.
/// Delays 20ms for latching
/// </summary>
/// <param name="bankId"></param>

void writeBank(uint8_t bankId)
{
    ////unsigned int timein = millis(); //debug timer

    uint8_t solIndex = bankId * 8; //we need to offset based on the bank we're setting.
    ////Serial.print(bankId,DEC);  Serial.print("B:");//debug

    //loop 0-7 to set the state of the 8 solenoids for this bank
    for(uint8_t pinIndex = 0; pinIndex < 8; pinIndex++)
    {
        //get the value of the solenoid from the full array.
        if (_sol_currentState[solIndex] > 0) // if this solenoid is marked ON
        {
            //if it has a maximum on timeout AND it has been on for that long
            if (_sol_maxOn[solIndex] != 0 && millis() - _sol_currentState[solIndex] >= _sol_maxOn[solIndex]) 
            {
                //on too long.  turn it off.
                _sol_currentState[solIndex] = 0;
                _sol_lastOn[solIndex] = millis();
                DebugPrint("Solenoid Overload.  Overriding to FALSE "); //not sure this should just reset the timer or kill it.
                DebugPrintLnByte(solIndex); //will this debug message screw up our state messages?
                digitalWrite(_powerBoardPins[pinIndex], LOW); //turn it off
                ////Serial.print("0");//debug
            }
            else //turn it on or leave it on
            {
                digitalWrite(_powerBoardPins[pinIndex], HIGH);
                ////Serial.print("1");//debug
            }
        }
        else //turn it off or leave it off
        {
            digitalWrite(_powerBoardPins[pinIndex], LOW);
            ////Serial.print("0");//debug
        }
        solIndex++;
    }
    ////Serial.println("");//debug
  
    //now set the bank latch HIGH, then back to LOW to lock in the values
    digitalWrite(_powerBoardPins[9 + bankId], HIGH);
    delayMicroseconds(100);  //?? What delay is long enough?
    digitalWrite(_powerBoardPins[9 + bankId], LOW); 
    ////Serial.println(timein - millis(), DEC);//debug
}
