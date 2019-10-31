#include "Linuxduino.h"

// Testing I2C read
int main(void) {

    Wire.begin("/dev/i2c-1");

    Wire.requestFrom(8, 6);           // Request 6 bytes from slave device #8

    int available = Wire.available(); // Check available bytes sent from slave device
    printf("Bytes available = %d \n", available);
    if (available == 0 ) {            // Make sure we have communication with the device.
        printf("Wrong I2C address or I2C wires may not be connected properly\n");
        return -1;
    }
    printf("Message recieved = ");
    while (Wire.available()) {
        char c = Wire.read();         // Read bytes as character
        printf("%c", c);
    }
    printf("\n");

    Wire.end();
    return 1;
}