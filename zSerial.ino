 //TODO: Put this in a more centralized header somewhere.
const uint8_t TOKEN_TERMINATE = 46; //"."
const uint8_t TOKEN_SWITCHSTATUS = 36; //"$"
const uint8_t TOKEN_COMMAND = 35; //"#"

const uint8_t ERR_NOERROR = 0;
const uint8_t ERR_SOLENOIDSOFFLINE = 100;
const uint8_t ERR_NOTIMPLEMENTED = 101;
const uint8_t ERR_UNKNOWNCOMMAND = 254;

//void writeArray(const uint8_t out[], uint32_t length)
//{    
//    Serial.write(TOKEN_SWITCHSTATUS);
//    for(uint8_t index = 1;index < length-1; index++)
//    {
//        Serial.write(out[index]);
//    }
//    Serial.write(TOKEN_TERMINATE);
//}

bool readCommand(uint8_t out[], uint8_t length)
{
    while (Serial.available() > 0)
    {
        while (Serial.peek() != TOKEN_COMMAND)
        {
            Serial.read();
            if (Serial.available() <= 0)
            {                
                break;
            }
        }

        if (Serial.available() <= 0)
        {
            return false;  //nothing to read.  got garbage.
        }
        else if (Serial.available() >= length) //got enough data
        {            
            //DebugPrintLn("GOT FULL COMMAND!");
            uint32_t count = 0;
            //Got a command header, lets fill up the response array
            while (Serial.available() && count < length)
            {
                out[count] = Serial.read();
                count++;
            }
            if (count == length)
                return true;
        }
        else
        {
            //DebugPrintLn("GOT PARTIAL COMMAND! WAITING");
        }
    }
    return false;
}

void printTime()
{
    Serial.println();
    Serial.println(millis());
}

uint8_t ParseCommand(uint8_t command[])
{
    //command array is 4 bytes long
    //b0: #
    //b1: {Disable,Fire,Enable}
    //b2: {All,# id of solenoid to Fire, (Dis/En)able}
    //b3: .
    switch(command[1])
    {
        case 68: //[D]isable
            DebugPrint("Got Command Disable:");
            if (command[2] == 65) //[A]ll
            {
                DebugPrintLn("All");
                EnableSolenoids(false);
            }
            else
            {
                DebugPrintLnByte(command[2]);
                return ERR_NOTIMPLEMENTED; //EnableSolenoids(command[2], false); //not implemented
            }
            break;
        case 69: //[E]nable
            DebugPrint("Got Command Enable:");
            if (command[2] == 65) //[A]ll
            {
                DebugPrintLn("All");
                EnableSolenoids(false);
            }
            else
            {
                DebugPrintLnByte(command[2]);
                return ERR_NOTIMPLEMENTED; //EnableSolenoids(command[2], true);
            }
            break;
        case 70: //[F]ire
            DebugPrint("Got Command Fire:");
            DebugPrintLnByte(command[2]);
            //if (command[2] >= 0 && command[i] < NUMSOLENOIDS)
            solenoidFireImmediate(command[2], true);
            //this should write to solenoidstate instead of fire immediate
            break;
        case 33: //! Debug Mode
            DebugPrintLn("Got Command Toggle Debug.");
            if (command[2] == 63) //[?]
            {
                return _spewDebug ? 1 : 0;
            }
            else if (command[2] == 49) //[1]
            {
                _spewDebug = true;
                DebugPrintLn("Debug Is Now ON."); //wont work if it's off
            }
            else if (command[2] == 48) //[0]
            {
                _spewDebug = false;
            }
            break;
        case 63: //?
            DebugPrintLn("Got Command Toggle SpewStatus.");
            if (command[2] == 63) //[?]
            {
                return _spewStatus ? 1 : 0;
            }
            else if (command[2] == 49) //[1]
            {
                _spewStatus = true;
                DebugPrintLn("SpewStatus Is Now ON.");
            }
            else if (command[2] == 48) //[0]
            {
                _spewStatus = false;
                DebugPrintLn("SpewStatus Is Now OFF.");
            }
            break;
        default:
            //don't understand command. //TODO: Error codes
            DebugPrint("Got Unknown Command:");
            DebugPrintLnByte(command[1]);
            return ERR_UNKNOWNCOMMAND;
    }
    return ERR_NOERROR;
}

void DebugPrint(String val)
{
    if (_spewDebug) Serial.print(val);
}
void DebugPrintLn(String val)
{
    if (_spewDebug) Serial.println(val);
}
void DebugPrintByte(uint8_t val)
{
    if (_spewDebug) Serial.print(val, DEC);
}
void DebugPrintLnByte(uint8_t val)
{
    if (_spewDebug) Serial.println(val, DEC);
}
void DebugPrintInt(uint32_t val)
{
    if (_spewDebug) Serial.print(val, DEC);
}
void DebugPrintLnInt(uint32_t val)
{
    if (_spewDebug) Serial.println(val, DEC);
}