#include "Linuxduino.h"

// Testing SPI beginTransaction
int main(void) {

    char ret;

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPISettings settingsA(SPI_CLOCK_DIV64, MSBFIRST, SPI_MODE3);

    // Send Hello World! every second
    while(1) {
        SPI.beginTransaction(settingsA);
        // Note in SPI the last character will not be printed here. 
        // In SPI you recieve what you sent previously. 
        for (const char *p = "Hello, world!\n" ; *p!=0 ; p++) {
            ret = SPI.transfer (*p); // Transmit and receive one byte
            printf("%c", ret);
        }
        SPI.endTransaction();
        printf("\n");        
        delay(1000); // delay 1 sec.
    }

    SPI.end(); 
    return 0;
}
