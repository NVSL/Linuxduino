#include "Linuxduino.h"

// Testing Serial findUntil
int main(void) {

    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Recieveng 'OK' will trigger a found, \
     recieveing 'x' will skip, 5 sec wait.\n");
    Serial.setTimeout(5000);
    while (1) {
        bool isOKFound = false;

        // If target OK found return true
        // If timeout or teminator "x" found return false
        isOKFound = Serial.findUntil("OK", "x");    //Wait 5 seconds
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