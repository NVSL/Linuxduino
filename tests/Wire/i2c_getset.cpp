#include "Linuxduino.h"

// Testing I2C write
int main(void) {

#ifdef __EMSCRIPTEN__
    setWire("/devices/i2c-1");
    Wire.begin();
#else 
    setWire("/dev/i2c-1");
    Wire.begin();
#endif

    printf("Current I2C Driver = %s \n", getWire());
    Wire.beginTransmission(8);
    Wire.write("Hello World");
    Wire.endTransmission();
    Wire.end();
    return 1;
}