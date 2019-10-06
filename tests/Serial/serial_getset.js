#include "Linuxduino.h"

// Testing Serial setSerial and getSerial
int main(void) {

    // Open Serial
    setSerial("/dev/ttyUSB0");
    Serial.begin(115200);

    printf("Current Serial Driver = %s \n", getSerial());
    Serial.println("Hello World");
    Serial.end();

    return 0;
}