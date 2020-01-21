# digitalRead()  

Reads the value from a specified digital pin, either HIGH or LOW.

## Syntax 
```
digitalRead(pin)
```
## Parameters

***pin***:   
  
The embedded board GPIO number. Must be a range from 0 to 256. 
If your embedded board GPIO goes over the available range contact me (jgarzagu at ucsd.edu). 

## Returns

HIGH or LOW

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Test digitalRead
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var ledPin = 17; // Embedded board GPIO Number
  var input = 0;
  linuxduino.pinMode(ledPin, linuxduino.INPUT);
  while(1) {
    input = linuxduino.digitalRead(ledPin);
    console.log(input);
    linuxduino.delay(500);
  }
  return 0;
})();
```

Run it
```js
sudo node digitalRead.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test digitalRead
int main(void) {
    int ledPin = 17; // Embedded board GPIO Number
    int input = 0;
    pinMode(ledPin, INPUT);
    while(1) {
        input = digitalRead(ledPin);
        printf("%d\n", input);
        delay(500);
    }
    return 0;
}
```

Run it
```sh
g++ digitalRead.cpp -o digitalRead -llxduino
sudo ./digitalRead
```