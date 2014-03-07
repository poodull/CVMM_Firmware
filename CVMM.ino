//#define MEGA true
//#define  __PIC32MX__ 1		//any Chipkit PIC
//#define  __32MX320F128H__ 1	//Uno32
#define  __32MX795F512L__ 1		//Max32
//#define  __AVR_ATmega1280__ 1 //Mega1280
//#define __AVR_ATmega2560__ 1	//Mega2650
//#define __SAM3X8E__ 1			//Due
//#define __AVR_ATmega328P__ 1	//Uno

void setup()
{    
  // set up serial 
  Serial.begin(115200);
  initializeSwitches();
#if defined (__AVR_ATmega1280__)
  setTimerInterrupt(); //the Mega needs a timer interrupt to make sure we revisit switches
#elif defined (__32MX795F512L__)
  //The Max32 is fast enough to just look at switches in the loop instead of interrupts
#endif
}

// SpewStatus turns on the byte array switch status output.  Off allows for debugging
bool _spewStatus = false;
// SpewDebug turns on Debug verbose messages (not usable for game play)
bool _spewDebug = true;
uint32_t _timer = 0;
double _timerCount = 0;
#define COMMANDSIZE  4 //# = start, Header, Parameter, . = close
uint8_t _commandIn[COMMANDSIZE];
uint8_t _commandCount = 0; //count the commands that come in to pair up responses

void loop()
{
#if defined (__32MX795F512L__)
    check_switches();
#endif
    _timer++;
    _timerCount++;
    //See if we have a command waiting for us from the game controller
    while (readCommand(_commandIn, COMMANDSIZE))
    {
        if (_commandCount == 255)
            _commandCount = 0;
        else 
            _commandCount++;
        //TODO: do something with this command
        uint8_t response = ParseCommand(_commandIn);
        if (!_spewDebug)
        {
            Serial.write("#");
            Serial.write(_commandCount); //The command count so we can pair up commands to responses.
            Serial.write(response); //The actual response.  NOTE: 0 != "0"
            Serial.write(".");
        }
        else
        {
            DebugPrintLnByte(response);
        }
    }

    //Write to our solenoid banks.  This should happen IMMEDIATELY after a command in case
    //we're told to kill power.
    writeBank(0);
    writeBank(1);
    writeBank(2);
    writeBank(3);

    //printTime(); //DEBUG
    //Write our switch state to the game controller so it can decide what to do with us.
    if (!writeSwitchStatus())
    {
        //didn't write status because it didn't change.
        //use this cycle to do something else
    }
    //if (_timer == 1000)
    //{
    //    Serial.println(millis() / _timerCount); //DEBUG THIS WILL OVERFLOW!!!
    //    _timer = 0;
    //    _timerCount++;
    //}
}

#if defined (__AVR_ATmega1280__)
uint32_t _timerValue; //I can't get this to interrupt longer than 2.? ms
void setTimerInterrupt()
{
    //disable the timer overflow interrupt during config
    TIMSK2 &= !(1<<TOIE2);

    //config timer2 in normal mode (pure counting, no pwm)
    TCCR2A &= ~((1<<WGM21) | (1<<WGM20));
    TCCR2B &= ~(1<<WGM22);

    //select clock source: internal i/o clock
    ASSR &= ~(1<<AS2);

    //disable compare match A interrupt enable (only want overflow)
    TIMSK2 &= ~(1<<OCIE2A);

    //now configure the prescaler to CPU clock divided by 128
    TCCR2B |= (1<<CS22) | (1<<CS20); //set bits
    TCCR2B &= ~(1<<CS21);
    
    //calculate a proper value to load the timer counter.
    //this loads the value 131 into the Timer 2 counter register.
    //(CPU freq) / (prescaler value) = 125000 Hz = 8us
    //(desired period) / 8us = 125
    //MAX(uint8) + 1 - 125 = 131;

    //Save value globally for later reload in ISR
    _timerValue = 1028; //this is just over 2ms.  most I can reliably get from Timer2

    //Finally, load and enable the timer
    TCNT2 = _timerValue;
    TIMSK2 |= (1<<TOIE2);
}

//install the interrupt Service Routing (ISR) for Timer 2 overflow.
//setting of 10 averages out to 10.32ms with NO LOAD
//setting of 10ms averages out to 10.36ms with Full DigitalRead
ISR(TIMER2_OVF_vect)
{
    static long lasttime;
    //reload the timer
    TCNT2 = _timerValue;

    //Check the state of the switches.  This should set our btn_XXX states.
    check_switches();
}
#endif

