#include "Linuxduino.h"

// Testing Serial writes
int main(void) {

    char buff[] = "Hello World";

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    if(Serial) { // This is just to test (if(Serial))
        Serial.write('A');
        Serial.write("Lol");
        Serial.write(buff, strlen(buff));
        Serial.write(0x41); // Sends explicit byte
        Serial.write('\r');
        Serial.write('\n');
    }

    Serial.end();

    return 1;
}