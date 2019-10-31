#include "Linuxduino.h"

// Testing spi transfer()
int main(void) {

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    // Test transfer(buffer, len)
    char msg[] = "Hello World!\n";
    SPI.transfer(msg, strlen(msg)); // Send Hello World!\n
    printf("Data Recieved = ");
    for (unsigned int i=0; i<strlen(msg); i++){
         printf("%c",msg[i]);
    }
    printf("\n");

    // Test transfer(buffer, len)
    char msg2[2] = {0x41, 0x0A};
    SPI.transfer(msg2, 2); // Send A\n
    printf("Data Recieved = ");
    for (unsigned int i=0; i<strlen(msg); i++){
         printf("%c",msg[i]);
    }
    printf("\n");

    // Test transfer(byte)
    char ret;
    ret = SPI.transfer(0x42); // Send 'B'
    printf("Data Recieved = %c\n", ret);
    ret = SPI.transfer(0x0A); // Send '\n'
    printf("Data Recieved = %c\n", ret);

    SPI.end(); 
    return 1;
}