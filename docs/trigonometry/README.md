## cos() 
## sin() 
## tan() 

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing TRIGONOMETRY functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  console.log("cos(3.1416) = ", linuxduino.cos(3.1416)); // -1...
  console.log("sin(3.1416) = ", linuxduino.sin(3.1416)); // -0...
  console.log("tan(3.1416) = ", linuxduino.tan(3.1416)); //  0...

})();
```

Run it
```js
node trigonometry.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test TRIGONOMETRY functions
int main(void) {

    printf("cos(3.1416) = %f \n", cos(3.1416)); // -1...
    printf("sin(3.1416) = %f \n", sin(3.1416)); // -0...
    printf("tan(3.1416) = %f \n", tan(3.1416)); //  0...

    return 1;
}
```

Run it
```sh
g++ trigonometry.cpp -o trigonometry -llxduino
./trigonometry
```