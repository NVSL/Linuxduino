#include "Linuxduino.h"

// Testing Serial writes
int main(void) {

    char buff[] = "Hello World";

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/devices/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif

    if(Serial) { // This is just to test (if(Serial))
        Serial.write('A');
        Serial.write("Lol");
        Serial.write(buff, strlen(buff));
        Serial.write('\r');
        Serial.write('\n');
    }

    Serial.end();

    return 1;
}