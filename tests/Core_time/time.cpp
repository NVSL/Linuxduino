#include "Linuxduino.h"

// Test TIME
int main(void) {

    // Test millis
    unsigned int start_millis = (unsigned int) millis();
    delay(1000); // Delay 1 sec
    unsigned int end_millis = (unsigned int) millis();
    printf("Delay 1000 millis  = %d \n", end_millis - start_millis);
    // Test micros
    unsigned int start_micros = (unsigned int) micros();
    delayMicroseconds(1000000); // Delay 1 sec
    unsigned int end_micros = (unsigned int) micros();
    printf("Delay 1000000 micros  = %d \n", end_micros - start_micros);

    return 1;
}