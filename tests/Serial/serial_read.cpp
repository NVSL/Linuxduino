#include "Linuxduino.h"

// Testing Serial read and available
int main(void) {

    char incomingByte;
    int availableBytes;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    printf("Write Something...\n");
    delay(5000);

    // Check if there is available data:
    if ((availableBytes = Serial.available()) > 0) {

        printf("Available bytes = %d\n", availableBytes);

        for (int i=0; i<availableBytes; i++) {
            // read incoming byte:
            incomingByte = Serial.read();
            // print incoming byte:
            printf("Incoming Byte %d: %c \n", i, incomingByte);
        }

    } else {
        printf("Nothing available \n");
    }

    Serial.end();

    return 1;
}