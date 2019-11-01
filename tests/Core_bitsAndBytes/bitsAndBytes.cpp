#include "Linuxduino.h"

// Test BITS AND BYTES functions
int main(void) {

    unsigned char value;

    // bit(1)
    printf("0x02 & bit(1) = %X \n", (unsigned char) (0x02 & bit(1)));
    // bitClear()
    value = 0x02;
    bitClear(value, 1);
    printf("bitClear(0x02, 1) = %X \n", value);
    // bitRead() 
    printf("bitRead(0x02, 1) = %X \n", bitRead(0x02, 1));
    // bitSet()
    value = 0x00;
    bitSet(value, 1);
    printf("bitSet(0x00, 1) = %X \n", value);
    // bitWrite()
    value = 0x00; 
    bitWrite(value, 0, 1);
    printf("bitWrite(0x00, 0, 1) = %X \n", value);
    // highByte()
    printf("highByte(0xABCD) = %X \n", highByte(0xABCD));
    // lowByte()
    printf("lowByte(0xABCD) = %X \n", lowByte(0xABCD));

    return 1;
}