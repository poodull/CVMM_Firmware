uint32_t boardFreqHz()
{
    return F_CPU;
}

//Converts an array[8] of 0s and 1s into a single byte via shifting
uint8_t arrayToByte(uint8_t src[])
{
    int i;
    uint8_t result = 0;

    for(i=7; i>=0; i--)
    {
        if (src[i] == 1)
        {
            result |= (1 << i);
        }
    }
    return result;
}

//Converts an array of 0s and 1s into a byte array (ie. [01101010] = 106).
//dest[] must be >= 1/8th the size of src[].
void arrayToByteArray(volatile uint8_t src[], uint8_t srclength, uint8_t dest[])
{
    uint8_t totalBytes = 0;
    uint8_t bitIndex = 0;
    uint8_t currentByte = 0;

    for(uint8_t index = 0; index < srclength; index++)
    {
        if (src[index] == 1)
        {
            currentByte |= (1 << bitIndex); //shift a 1 into bitIndex's place in currentByte
        }
        bitIndex++; //move left on the byte index
        if (bitIndex == 7) //filled the last bit of currentByte
        {
            dest[totalBytes] = currentByte;
            currentByte = 0;
            bitIndex = 0;
            totalBytes++;
        }
    }
    if (bitIndex < 7) //we're done with the src array, but didn't finish cleanly.
    {
        dest[totalBytes] = currentByte;
    }
}

uint32_t* byteToArray(uint8_t in) //not tested
{
    uint32_t i, temp, out[8];

    for(i = 0; i < 8; i++)
    {
        temp = (in >> i ) & 1;
        if (temp == 0) temp = 1;
        out[i] = temp;
    }
    return out;
}
