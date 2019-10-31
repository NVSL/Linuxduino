#include "Linuxduino.h"

// Testing Serial setSerial and getSerial
int main(void) {

    // Open Serial port
    setSerial("/dev/ttyUSB0");
    Serial.begin(115200);

    printf("Current Serial Driver = %s \n", getSerial());
    printf("Sending Hello World...\n");
    Serial.println("Hello World");
    Serial.end();

    return 0;
}