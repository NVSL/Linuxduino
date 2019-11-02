## abs() 
## constrain() 
## map() 
## max() 
## min() 
## pow() 
## sq() 
## sqrt() 
## round()
## radians()
## degrees()

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing MATH functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  console.log("abs (-11) = ", linuxduino.abs(-11));
  console.log("constrain (3, 10, 150) = ", linuxduino.constrain(3,10,150));
  console.log("constrain (151, 10, 150) = ", linuxduino.constrain(151,10,150));
  console.log("constrain (50, 10, 150) = ", linuxduino.constrain(50,10,150));
  console.log("map (5, 0, 10, -10, -20) = ", linuxduino.map (5, 0, 10, -10, -20));
  console.log("max (4,6) = ", linuxduino.max(4,6));
  console.log("min (4,6) = ", linuxduino.min(4,6));
  console.log("pow(2,3) = ", linuxduino.pow(2,3));
  console.log("sqrt(4) = ", linuxduino.sqrt(4));
  console.log("sq(2) = ", linuxduino.sq(2));
  console.log("round(4.678) = ", linuxduino.round(4.678));
  console.log("radians(180) = ", linuxduino.radians(180));
  console.log("degrees(3.141593) = ", linuxduino.degrees(3.141593));

})();
```

Run it
```js
node math.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test MATH functions
int main(void) {

    printf("abs (-11) = %d \n", abs(-11));
    printf("constrain (3, 10, 150) = %d \n", constrain(3,10,150));
    printf("constrain (151, 10, 150) = %d \n", constrain(151,10,150));
    printf("constrain (50, 10, 150) = %d \n", constrain(50,10,150));
    printf("map (5, 0, 10, -10, -20) = %d \n", (int) map (5, 0, 10, -10, -20));
    printf("max (4,6) = %d \n", max(4,6));
    printf("min (4,6) = %d \n", min(4,6));
    printf("pow(2,3) = %f \n", pow(2,3));
    printf("sq(2) = %d \n", sq(2));
    printf("sqrt(4) = %f \n", sqrt(4));
    printf("round(4.678) = %f \n",round(4.678));
    printf("radians(180) = %f \n", radians(180));
    printf("degrees(3.141593) = %f \n", degrees(3.141593));

    return 1;
}
```

Run it
```sh
g++ math.cpp -o math -llxduino
./math
```