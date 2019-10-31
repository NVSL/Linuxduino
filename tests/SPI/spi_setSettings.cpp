#include "Linuxduino.h"

// Testing SPI separate settings
int main(void) {

    char ret;

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    // Send Hello World! every second
    while(1) {
        // Note in SPI the last character will not be printed here. 
        // In SPI you recieve what you sent previously. 
        for (const char *p = "Hello World!\n" ; *p!=0 ; p++) {
            ret = SPI.transfer(*p); // Transmit and receive one byte
            printf("%c", ret);
        }
        printf("\n");
        delay(1000); // delay 1 sec.
    }

    SPI.end(); 
    return 0;
}
