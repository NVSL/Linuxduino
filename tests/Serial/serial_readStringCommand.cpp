#include "Linuxduino.h"

// Testing Serial readStringCommand
int main(void) {

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write something...\n");

    // Read string and wait for "enter"
    // Works as a termial (Ctrl^C to terminate)
    while(1) {
        char data[50];
        memset(data, 0, sizeof(data));
        //  Read
        Serial.readStringCommand('\r', data, sizeof(data));
        printf ("Recieved = %s\n", data);
    }

    Serial.end();

    return 1;
}