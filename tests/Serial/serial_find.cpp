#include "Linuxduino.h"

// Testing Serial find
int main(void) {

 #ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/devices/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif

    printf("Write something (Writing 'OK' will trigger a found, 5 sec wait)...\n");
    Serial.setTimeout(5000);
    while (1) {
        bool isOKFound = false;

        // If target OK found return true, if timeout return false
        isOKFound = Serial.find("OK");    //Wait for 'OK' for 10 seconds
        if (isOKFound) {
            printf("OK found\n");
        } else {
            printf("Noting found\n");
        }

        Serial.flush();

        printf("Time OVER\n");
    }

    Serial.end();

    return 1;
}
