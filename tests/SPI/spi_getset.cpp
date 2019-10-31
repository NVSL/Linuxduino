#include "Linuxduino.h"

// Testing SPI set/get
int main(void) {

    char ret;

    setSPI("/dev/spidev0.0");
    printf("Current SPI Driver = %s \n", getSPI());

    // Open SPI port
    SPI.begin();

    // Set SPI Settings
    SPISettings settingsA(SPI_CLOCK_DIV64, MSBFIRST, SPI_MODE3);

    // Send Hello World!
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously. 
    for (const char *msg = "Hello World!\n" ; *msg!=0 ; msg++) {
        ret = SPI.transfer(*msg);
        printf("%c", ret);
    }
    SPI.endTransaction();
    printf("\n");
    
    SPI.end(); 
    return 1;
}
