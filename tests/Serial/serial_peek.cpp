#include "Linuxduino.h"

// Testing Serial peek
// peek, -1 when nothing and afected by timeOut 
// Checks the next char of the serial without removing it.
int main(void) {

    char peekChar;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
        
    // Note: peek should not block.
    printf("Write Something...\n");
    delay(5000);
    peekChar = Serial.peek();
    printf("Your next char is = %c\n", peekChar);

    Serial.end();

    return 1;
}