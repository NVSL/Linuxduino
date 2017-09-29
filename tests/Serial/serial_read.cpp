#include "Linuxduino.h"
#include "unistd.h" // For sleep()

// Testing Serial read and available
int main(void) {

    char incomingByte;
    int availableBytes;

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/devices/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif
    
    printf("Write Something...\n");
    sleep(5);

    // send data only when you receive data:
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