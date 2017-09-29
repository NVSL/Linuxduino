#include "Linuxduino.h"
#include "unistd.h" // For sleep()

// Testing SPI settings
int main(void) {

    char ret;

#ifdef __EMSCRIPTEN__
    setSPI("/devices/spidev0.0");
    SPI.begin();
#else 
    setSPI("/dev/spidev0.0");
    SPI.begin();
#endif

    printf("Current SPI Driver = %s \n", getSPI());

    SPISettings settingsA(SPI_CLOCK_DIV64, MSBFIRST, SPI_MODE3);
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously. 
    for (const char *p = "Hello, world!\n" ; *p!=0 ; p++) {
        ret = SPI.transfer (*p);
        printf("%c", ret);
    }
    printf("\n");
    SPI.endTransaction();
    SPI.end(); 
    return 1;
}
