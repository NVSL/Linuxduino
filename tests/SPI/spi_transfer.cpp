#include "Linuxduino.h"

// Testing spi transfer(buf,len)
int main(void) {

#ifdef __EMSCRIPTEN__
    SPI.begin("/devices/spidev0.0");
#else 
    SPI.begin("/dev/spidev0.0");
#endif

    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    char c[] =  "Hello, World!-";
    SPI.transfer (c, strlen(c));

    printf("Data Recieved = \n");
    // The last character sent will be printed first after
    for (unsigned int i=0; i<strlen(c); i++){
         printf("%c",c[i]);
    }
    printf("\n");

    SPI.end(); 
    return 1;
}
