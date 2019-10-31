#include "Linuxduino.h"

// Testing Serial readBytesUntil, setTimeout
int main(void) {

    char buff[100];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    printf("Write Something (reads until letter x or timeout of 5 sec)...\n");

    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    // Clean buffer
    for (int i = 0; i<10; i++) {
        buff[i] = 0;
    }

    // Read bytes until x is found or timeout
    Serial.readBytesUntil('x', buff, 100);
    buff[99] = 0;
    printf("Recieved = %s\n", buff);

    Serial.end();

    return 1;
}