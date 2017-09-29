#include "Linuxduino.h"

// Test digitalWrite
int main(void) {
    int ledPin = 4; // GPIO4
    pinMode(ledPin, OUTPUT);
    while(1) {
        printf("LED ON\n");
        digitalWrite(ledPin, HIGH);
        delay(1000);
        printf("LED OFF\n");
        digitalWrite(ledPin, LOW);
        delay(1000);
    }
    return 0;
}