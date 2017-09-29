#include "Linuxduino.h"

// Test setPwmFrequency
int main(void) {
    int pwmOut = 4; // GPIO18
    //pinMode(pwmOut, PWM_OUTPUT); // Soft PWM
    pinMode(pwmOut, OUTPUT); // Soft PWM

    // Check led change dutycycle for 1Hz (1 sec)
    printf("Change in dutycycle (1Hz)\n");
    setPwmFrequency(pwmOut, 1, 50);
    delay(5000);
    setPwmFrequency(pwmOut, 1, 200);
    delay(5000);

    // Check led change dutycycle for 2Hz (0.5 sec)
    printf("Change in dutycycle (2Hz)\n");
    setPwmFrequency(pwmOut, 2, 50);
    delay(5000);
    setPwmFrequency(pwmOut, 2, 200);
    delay(5000);

    // Check increase in freceuncy
    printf("Change in frequency (0Hz-60Hz)\n");
    for (int i=0; i<60; i++) {
        printf("%dHz\n", i);
        setPwmFrequency(pwmOut, i, 127);
        delay(1000);
    }
}