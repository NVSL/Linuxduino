#include "Linuxduino.h"

// Testing I2C read
// TODO Check with another arduino what happens if Wire.onRequest(requestEvent);
// is removed. In this case linux I2C still reads Bytes avilable = 6. 
int main(void) {

 #ifdef __EMSCRIPTEN__
    Wire.begin("/devices/i2c-1");
#else 
    Wire.begin("/dev/i2c-1");
#endif

    Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8

    int available = Wire.available();
    printf("Bytes available = %d \n", available);
    printf("Message recieved = ");
    while (Wire.available()) { // slave may send less than requested
        char c = Wire.read(); // receive a byte as character
        printf("%c", c);
    }
    printf("\n");

    return 0;
}