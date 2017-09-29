#include "Linuxduino.h"
#include "unistd.h" // For sleep()

// Testing SPI Separate settings
int main(void) {

    char ret;

#ifdef __EMSCRIPTEN__
    SPI.begin("/devices/spidev0.0");
#else 
    SPI.begin("/dev/spidev0.0");
#endif

    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    while(1) {
        // Note in SPI the last character will not be printed here. 
        // In SPI you recieve what you sent previously. 
        for (const char *p = "Hello, world!\n" ; *p!=0 ; p++) {
            ret = SPI.transfer (*p);
            printf("%c", ret);
        }

        sleep(1); // delay 1 sec.
    }

    SPI.end(); 
    return 0;
}
