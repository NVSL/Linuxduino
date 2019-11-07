#include "Linuxduino.h"

// Test digitalRead
int main(void) {
    int ledPin = 17; // Embedded board GPIO Number
    int input = 0;
    pinMode(ledPin, INPUT);
    while(1) {
        input = digitalRead(ledPin);
        printf("%d\n", input);
        delay(500);
    }
    return 0;
}