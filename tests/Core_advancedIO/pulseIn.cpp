#include "Linuxduino.h"

// Test pulseIn 
int main(void) {
    const byte inPin = 17;
    int duration = 0;
    pinMode(inPin, INPUT);
    while (1) {
        printf("Press button\n");
        duration = pulseIn(inPin, HIGH);
        //duration = pulseIn(inPin, HIGH, 10000000); // wait 10 seconds
        printf("Duration = %d\n", duration);
    }
}