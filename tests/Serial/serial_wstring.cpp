#include "Linuxduino.h"

// Testing Serial WString
int main(void) {

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/drivers/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif

    std::string normalstr = "A normal string";
    Serial.println(normalstr.c_str());      // prints "Hello String"

    // using a constant String:
    String stringOne = "Hello String";
    Serial.println(stringOne);      // prints "Hello String"

    // converting a constant char into a String:
    stringOne =  String('a');
    Serial.println(stringOne);       // prints "a"

    // converting a constant string into a String object:
    String stringTwo =  String("This is a string");
    Serial.println(stringTwo);      // prints "This is a string"

    // concatenating two strings:
    stringOne =  String(stringTwo + " with more");
    // prints "This is a string with more":
    Serial.println(stringOne);

    // using a constant integer:
    stringOne =  String(13);
    Serial.println(stringOne);      // prints "13"

    // using an int and a base:
    stringOne =  String(15, DEC);
    // prints "453" or whatever the value of analogRead(A0) is
    Serial.println(stringOne);

    // using an int and a base (hexadecimal):
    stringOne =  String(45, HEX);
    // prints "2d", which is the hexadecimal version of decimal 45:
    Serial.println(stringOne);

    // using an int and a base (binary)
    stringOne =  String(255, BIN);
    // prints "11111111" which is the binary value of 255
    Serial.println(stringOne);

    // using a long and a base:
    long lal = 123123123;
    stringOne =  String(lal, DEC);
    // prints "123456" or whatever the value of millis() is:
    Serial.println(stringOne);

    //using a float and the right decimal places:
    stringOne = String(5.698, 3);
    Serial.println(stringOne);

    //using a float and less decimal places to use rounding:
    stringOne = String(5.698, 2);
    Serial.println(stringOne);

    Serial.end();

    return 1;
}