#include "Linuxduino.h"

// Testing I2C write
int main(void) {

    char world[] = "World!";

#ifdef __EMSCRIPTEN__
    Wire.begin("/devices/i2c-1");
#else 
    Wire.begin("/dev/i2c-1");
#endif

    Wire.beginTransmission(8);
    Wire.write("Hello");
    Wire.write('|');
    Wire.write(world, strlen(world));
    Wire.endTransmission();
    Wire.end();
    return 1;
}