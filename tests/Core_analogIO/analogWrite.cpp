#include "Linuxduino.h"

// Test analogWrite
int main(void) {
    int pwmOut = 4; // GPIO18
    pinMode(pwmOut, OUTPUT); // Soft PWM
    // Check led increase in brightness
    for (int i = 0; i< 256; i++) {
    	analogWrite(pwmOut, i);
    	delay(50); // Delay 50 millisec
    	printf("DutyCycle = %d percentage = %d%% \n", i, (i*100/255));
    }
}