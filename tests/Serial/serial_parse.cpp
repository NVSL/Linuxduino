#include "Linuxduino.h"

// Testing Serial parseInt, prarseFloat
// Use another terminal for this.
// parseX waits until a character that is not a number is returned.  
int main(void) {

    int Intvalue;
    float Floatvalue;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write Some Int...\n");
    delay(5000);
    Intvalue = Serial.parseInt();
    printf("Your number Int Num is = %d\n", Intvalue);
    printf("Write Some Int (1 ignored)...\n");
    delay(5000);
    Intvalue = Serial.parseInt('1');
    printf("Your number Int Num is = %d\n", Intvalue);
    printf("Write Some Double...\n");
    delay(5000);
    Floatvalue = Serial.parseFloat();
    printf("Your number is = %g\n", Floatvalue);

    Serial.end();

    return 1;
}