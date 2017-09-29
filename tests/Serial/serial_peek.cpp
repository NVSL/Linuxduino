#include "Linuxduino.h"
#include "unistd.h" // For sleep()

// Testing Serial peek
// peek, -1 when nothing and afected by timeOut 
// Checks the next char of the serial without removing it.
int main(void) {

    char peekChar;

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/devices/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif
        
    // Note: peek should not block.
    printf("Write Something...\n");
    sleep(5);
    peekChar = Serial.peek();
    printf("Your next char is = %c\n", peekChar);
    peekChar = Serial.peek();
    printf("Your next char is = %c\n", peekChar);

    Serial.end();

    return 1;
}