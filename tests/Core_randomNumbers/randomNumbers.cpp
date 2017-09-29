#include "Linuxduino.h"

// Test RANDOM NUMBERS
int main(void) {

    randomSeed(10);
    printf("random(10) = %d \n", (int) random(10));
    printf("random(10) = %d \n", (int) random(10));
    printf("random(10) = %d \n", (int) random(10));
    printf("random(10) = %d \n", (int) random(10));
    printf("random (5, 10) = %d \n", (int) random(5, 10));
    printf("random (5, 10) = %d \n", (int) random(5, 10));
    printf("random (5, 10) = %d \n", (int) random(5, 10));
    printf("random (5, 10) = %d \n", (int) random(5, 10));
    
    return 1;
}