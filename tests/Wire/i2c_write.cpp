#include "Linuxduino.h"

// Testing I2C write
int main(void) {

    char world[] = "World";

    Wire.begin("/dev/i2c-1");

    // Send Hello World! to device
    Wire.beginTransmission(8); // 7-bit device I2C address
    Wire.write("Hello");
    Wire.write(0x57); // W Ascii
    Wire.write(' ');
    Wire.write(world, strlen(world));
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