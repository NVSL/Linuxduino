#include "Linuxduino.h"

// Testing set/get I2C device name
int main(void) {

    setWire("/dev/i2c-1");
    printf("Current I2C Driver = %s \n", getWire());

    // Open I2C port
    Wire.begin(); 

    Wire.beginTransmission(8); // 7-bit device I2C address
    Wire.write("Hello World");
    int bytes_transmitted = Wire.endTransmission();
    // Make sure transmission was sucessful
    if (bytes_transmitted == 0 ) {
        printf("Wrong I2C address or I2C wires may not be connected properly\n");
        return -1;
    }
    printf("Hello World msg sent! \n");

    Wire.end();
    return 1;
}