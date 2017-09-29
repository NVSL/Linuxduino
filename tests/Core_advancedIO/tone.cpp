#include "Linuxduino.h"

// Test pulseIn
// Note: Use a passive buzzer for this tests  
int main(void) {
    const byte pwmPin = 4;
    //pinMode(pwmPin, PWM_OUTPUT); 	// Soft PWM
    pinMode(pwmPin, OUTPUT); 		// Soft PWM
    tone(pwmPin, 1000, 1000, 1); // 1khz, 1 sec, block
    tone(pwmPin, 2000, 1000, 1); // 2khz, 1 sec, block
    tone(pwmPin, 3000, 1000, 1); // 3khz, 1 sec, block
    tone(pwmPin, 4000, 1000, 1); // 4khz, 1 sec, block
}