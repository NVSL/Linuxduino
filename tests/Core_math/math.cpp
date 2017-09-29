#include "Linuxduino.h"

// Test MATH
int main(void) {

    printf("min (4,6) = %d \n", min(4,6));
    printf("max (4,6) = %d \n", max(4,6));
    printf("abs (-11) = %d \n", abs(-11));
    printf("constrain (3, 10, 150) = %d \n", constrain(3,10,150));
    printf("constrain (151, 10, 150) = %d \n", constrain(151,10,150));
    printf("constrain (50, 10, 150) = %d \n", constrain(50,10,150));
    printf("map (5, 0, 10, -10, -20) = %d \n", (int) map (5, 0, 10, -10, -20));
    printf("pow(2,3) = %f \n", pow(2,3));
    printf("round(4.678) = %f \n",round(4.678));
    printf("radians(180) = %f \n", radians(180));
    printf("degrees(3.141593) = %f \n", degrees(3.141593));
    printf("sqrt(4) = %f \n", sqrt(4));
    printf("sq(2) = %d \n", sq(2));

    return 1;
}