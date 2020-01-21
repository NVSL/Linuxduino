# digitalWrite()  

Writes a HIGH or a LOW value to a digital pin. 

## Syntax 
```
digitalWrite(pin, value)
```
## Parameters

***pin***:   
  
The embedded board GPIO number. Must be a range from 0 to 256. 
If your embedded board GPIO goes over the available range contact me (jgarzagu at ucsd.edu). 

***value***:

HIGH or LOW

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Test digitalWrite
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var ledPin = 4; // Embedded board GPIO Number
  linuxduino.pinMode(ledPin, linuxduino.OUTPUT);
  while(1) {
    console.log("LED ON");
    linuxduino.digitalWrite(ledPin, linuxduino.HIGH);
    linuxduino.delay(1000); // Delay 1 sec
    console.log("LED OFF");
    linuxduino.digitalWrite(ledPin, linuxduino.LOW);
    linuxduino.delay(1000); // Delay 1 sec
  }
  return 0;
})();
```

Run it
```js
sudo node digitalWrite.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test digitalWrite
int main(void) {
    int ledPin = 4; // Embedded board GPIO Number
    pinMode(ledPin, OUTPUT);
    while(1) {
        printf("LED ON\n");
        digitalWrite(ledPin, HIGH);
        delay(1000); // Delay 1 sec
        printf("LED OFF\n");
        digitalWrite(ledPin, LOW);
        delay(1000); // Delay 1 sec
    }
    return 0;
}
```

Run it
```sh
g++ digitalWrite.cpp -o digitalWrite -llxduino
sudo ./digitalWrite
```