## random() 
## randomSeed() 

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Test RANDOM NUMBERS functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  linuxduino.randomSeed(10);
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
    
})();
```

Run it
```js
node randomNumbers.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test RANDOM NUMBERS functions
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
```

Run it
```sh
g++ randomNumbers.cpp -o randomNumbers -llxduino
./randomNumbers
```