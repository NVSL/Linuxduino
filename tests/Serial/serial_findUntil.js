#include "Linuxduino.h"

// Testing Serial findUntil
int main(void) {

    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    printf("Write something (Writing 'OK' will trigger a found, 5 sec wait or 'x')...\n");
    Serial.setTimeout(10000);
    while (1) {
        bool isOKFound = false;

        // If target OK found return true, if timeout or teminator "l" found return false
        isOKFound = Serial.findUntil("OK", "x");    //Wait for 'OK' for 10 seconds
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