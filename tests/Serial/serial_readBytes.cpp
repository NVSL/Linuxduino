#include "Linuxduino.h"

// Testing Serial readBytes
int main(void) {

    char buff[10];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    printf("Write Something (Recieves max 5 bytes)...\n");
    delay(5000);

    // Clean buffer
    for (int i = 0; i<10; i++) {
        buff[i] = 0;
    }

    //  Read 5 bytes
    Serial.readBytes(buff, 5);
    buff[5] = 0;
    printf("Recieved = %s\n", buff);

    Serial.end();

    return 1;
}