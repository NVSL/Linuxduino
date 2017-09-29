#include "Linuxduino.h"

// Testing Serial readStringCommand
int main(void) {

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/drivers/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif

    while (!Serial) { // Just test if(Serial)
        printf("Waiting for Serial ...\n");
    }

    printf("Write something...\n");
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