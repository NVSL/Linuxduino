#include "Arduino.h"

// Test Arduino style digitalWrite

int ledPin = 4; // GPIO4

void setup () {
    pinMode(ledPin, OUTPUT);
}

void loop () {
    printf("LED ON\n");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    printf("LED OFF\n");
    digitalWrite(ledPin, LOW);
    delay(1000);
}