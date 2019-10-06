#include "Arduino.h"

// Test Arduino digitalRead

int ledPin = 17; // GPIO4
int input = 0;

void setup() {
	pinMode(ledPin, INPUT);
}

void loop() {
    input = digitalRead(ledPin);
    printf("%d\n", input);
    delay(500);
}