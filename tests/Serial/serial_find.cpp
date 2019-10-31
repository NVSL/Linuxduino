#include "Linuxduino.h"

// Testing Serial find
int main(void) {

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Waiting to recieve OK ('OK' will trigger a found message)...\n");
    Serial.setTimeout(5000); // Wait 5 seconds
    while (1) {
        bool isOKFound = false;

        // If target OK found return true, if timeout return false
        isOKFound = Serial.find("OK");    //Wait for 'OK' for 5 sec
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
