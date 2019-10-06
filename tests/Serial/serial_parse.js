#include "Linuxduino.h"
#include "unistd.h" // For sleep()

// Testing Serial parseInt, prarseFloat
// Use another terminal for this.
// parseX waits until a character that is not a number is returned.  
int main(void) {

    int Intvalue;
    float Floatvalue;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    printf("Write Some Int...\n");
    sleep(5);
    Intvalue = Serial.parseInt();
    printf("Your number Int Num is = %d\n", Intvalue);
    printf("Write Some Int (1 ignored)...\n");
    sleep(5);
    Intvalue = Serial.parseInt('1');
    printf("Your number Int Num is = %d\n", Intvalue);
    printf("Write Some Double...\n");
    sleep(5);
    Floatvalue = Serial.parseFloat();
    printf("Your number is = %g\n", Floatvalue);

    Serial.end();

    return 1;
}