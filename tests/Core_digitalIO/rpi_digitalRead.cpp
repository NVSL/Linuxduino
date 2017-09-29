#include "Linuxduino.h"

// Test RaspberryPi digitalRead 
int main(void) {
    int ledPin = 17; // GPIO4
    int input = 0;
    pinMode(ledPin, RPI_INPUT);
    while(1) {
        input = digitalRead(ledPin);
        printf("%d\n", input);
        delay(500);
    }
    return 0;
}