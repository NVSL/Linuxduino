## delay()

## delayMicroseconds()

## micros()

## mills()

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing TIME functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

    // Test millis
    var start_millis = linuxduino.millis();
    linuxduino.delay(1000); // Delay 1 sec
    var end_millis = linuxduino.millis();
    console.log("Delay 1000 millis = ", end_millis - start_millis);

    // Test micros
    var start_micros = linuxduino.micros();
    linuxduino.delayMicroseconds(1000000); // Delay 1 sec
    var end_micros = linuxduino.micros();
    console.log("Delay 1000000 micros = ", end_micros - start_micros);

})();
```

Run it
```js
node time.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test TIME functions
int main(void) {

    // Test millis
    unsigned int start_millis = (unsigned int) millis();
    delay(1000); // Delay 1 sec
    unsigned int end_millis = (unsigned int) millis();
    printf("Delay 1000 millis  = %d \n", end_millis - start_millis);
    
    // Test micros
    unsigned int start_micros = (unsigned int) micros();
    delayMicroseconds(1000000); // Delay 1 sec
    unsigned int end_micros = (unsigned int) micros();
    printf("Delay 1000000 micros  = %d \n", end_micros - start_micros);

    return 1;
}
```

Run it
```sh
g++ time.cpp -o time -llxduino
./time
```