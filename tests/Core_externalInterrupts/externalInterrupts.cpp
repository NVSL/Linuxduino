#include "Linuxduino.h"

// Test attachInterrupt, detachInterrupt
// Currently no support for WEBASSEMBLY
const byte ledPin = 4;
const byte interruptPin = 17;
volatile byte state = LOW;
volatile boolean unattach = false;
volatile int counter = 0;

void blink() {
  state = !state;
  printf("On interrupt \n");
  digitalWrite(ledPin, state);
  // if Counter >= 20 detachInterrupt
  if (counter >= 20) {
    unattach = true;
  }
  counter ++;
}

int main(void) {
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
    digitalWrite(ledPin, state); // Set led to initial state (LOW)
    printf("Press Button on GPIO%d to generate interrupts\n", interruptPin);
    while (1) {
        if (unattach) {
            printf("Detaching\n");
            detachInterrupt(digitalPinToInterrupt(interruptPin));
            unattach = false;
            state = LOW;
        }
    }
}