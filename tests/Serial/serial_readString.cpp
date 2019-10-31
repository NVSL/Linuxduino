#include "Linuxduino.h"

// Testing Serial readString
int main(void) {

    String data = ""; // You can use std:string or char *
    
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write Something...\n");

    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    // Read data as string until timeout 
    data = Serial.readString();
    printf ("Recieved data = %s \n",data.c_str());

    Serial.end();

    return 1;
}