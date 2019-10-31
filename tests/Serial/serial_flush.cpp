#include "Linuxduino.h"

// Testing Serial flush
int main(void) {

    // Memory allocation
    char buff[10];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    printf("Write something on the other terminal (5 sec wait)...\n");
    delay(5000);

    //  Read 2 bytes
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 1 = %s\n", buff);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    // Clear Serial buffer
    Serial.flush();

    //  Read 2 bytes (Should print nothing - flush)
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 2 = %s\n", buff);

    Serial.end();

    return 1;
}