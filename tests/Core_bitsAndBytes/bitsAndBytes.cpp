#include "Linuxduino.h"

// Test BITS AND BYTES
int main(void) {

    unsigned char value;
    printf("lowByte(0xABCD) = %X \n", lowByte(0xABCD));
    printf("highByte(0xABCD) = %X \n", highByte(0xABCD));
    printf("bitRead(0x02, 1) = %X \n", bitRead(0x02, 1));
    value = 0x00; 
    bitWrite(value, 0, 1);
    printf("bitWrite(0x00, 0, 1) = %X \n", value);
    value = 0x00;
    bitSet(value, 1);
    printf("bitSet(0x00, 1) = %X \n", value);
    value = 0x02;
    bitClear(value, 1);
    printf("bitClear(0x02, 1) = %X \n", value);
    printf("0x02 & bit(1) = %X \n", (unsigned char) (0x02 & bit(1)));

    return 1;
}