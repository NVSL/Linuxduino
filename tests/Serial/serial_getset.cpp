#include "Linuxduino.h"

// Testing Serial setSerial and getSerial
int main(void) {

#ifdef __EMSCRIPTEN__
    // Open Serial
    setSerial("/devices/ttyUSB0");
    Serial.begin(115200);
#else 
    // Open Serial
    setSerial("/dev/ttyUSB0");
    Serial.begin(115200);
#endif

    printf("Current Serial Driver = %s \n", getSerial());
    Serial.println("Hello World");
    Serial.end();

    return 0;
}