#include "Linuxduino.h"

// Testing Serial readStringUntil
int main(void) {

    String data = "";

#ifdef __EMSCRIPTEN__
    // Open Serial
    Serial.begin("/devices/ttyUSB0", 115200, SERIAL_8N1);
#else 
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
#endif

    printf("Write Something (reads until letter x or timeout of 5 sec)......\n");
    //sleep(5);
    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    data = Serial.readStringUntil('x');
    printf ("Recieved data = %s \n",data.c_str());

    Serial.end();

    return 1;
}