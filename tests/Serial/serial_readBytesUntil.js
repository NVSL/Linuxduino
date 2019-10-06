#include "Linuxduino.h"

// Testing Serial readBytesUntil, setTimeout
int main(void) {

    char buff[100];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
    
    printf("Write Something (reads until letter x or timeout of 5 sec)...\n");
    //sleep(5);
    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    // Clean buffer
    for (int i = 0; i<10; i++) {
        buff[i] = 0;
    }

    //  Read 5 bytes
    Serial.readBytesUntil('x', buff, 100);
    buff[99] = 0;
    printf("Recieved = %s\n", buff);

    Serial.end();

    return 1;
}