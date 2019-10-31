#include "Linuxduino.h"

// Testing Serial print, println, printf
int main(void) {

	char message[] = "A char message";

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    // Printf
    Serial.printf("\n\r ---- Testing printf, print, println ----- \n\r");
    Serial.printf("Integer = %d, Float = %f, Char = %c, String = %s \n\r", 
                10, 3.1416, 'a', "Hello World");

    // Print
    Serial.print("A const char message ");
    Serial.print("(no new line)");
    Serial.println("A const char message ");
    Serial.println("(new line)");
    Serial.print(message);
    Serial.println(message);

    // Println
    Serial.println(15, DEC);
    Serial.println(15, OCT);
    Serial.println(15, HEX);
    Serial.println(15, BIN);
    Serial.println(-15, DEC);
    Serial.println(-15, OCT);
    Serial.println(-15, HEX);
    Serial.println(-15, BIN);

    // Send explicit byte
    Serial.print(0x41);    // Sends ascii A
    Serial.println(0x42);  // Sends ascii B

    Serial.end();

    return 0;
}
