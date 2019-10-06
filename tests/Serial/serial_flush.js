#include "Linuxduino.h"
#include "unistd.h" // for sleep();

// Testing Serial flush
int main(void) {

    char buff[10];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    printf("Write Something...\n");
    sleep(5);

    //  Read 2 bytes
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 1 = %s\n", buff);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    // Clear Serial buffer
    Serial.flush();

    //  Read 2 bytes (Should print nothing)
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 2 = %s\n", buff);

    Serial.end();

    return 1;
}