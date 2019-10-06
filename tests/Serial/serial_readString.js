#include "Linuxduino.h"

// Testing Serial readString
int main(void) {

    String data = "";
    
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    printf("Write Something...\n");
    //sleep(5);
    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    data = Serial.readString();
    printf ("Recieved data = %s \n",data.c_str());

    Serial.end();

    return 1;
}