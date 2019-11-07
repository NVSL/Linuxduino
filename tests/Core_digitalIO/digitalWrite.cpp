#include "Linuxduino.h"

// Test digitalWrite
int main(void) {
    int ledPin = 4; // Embedded board GPIO Number
    pinMode(ledPin, OUTPUT);
    while(1) {
        printf("LED ON\n");
        digitalWrite(ledPin, HIGH);
        delay(1000); // Delay 1 sec
        printf("LED OFF\n");
        digitalWrite(ledPin, LOW);
        delay(1000); // Delay 1 sec
    }
    return 0;
}