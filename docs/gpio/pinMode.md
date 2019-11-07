## pinMode() 

## Syntax 
```
pinMode(pin, mode)
```
## Parameters

***pin***:   
  
The embedded board GPIO number. Must be a range from 0 to 256. 
If your embedded board GPIO goes over the available range contact me (jgarzagu at ucsd.edu).  
  
***mode***:  
  
Standard modes:  
**INPUT**: Sets GPIO pin number as input.  
**INPUT_PULLDOWN**: Same effect as INPUT since some embedded boards doesn't have PULL resistos internally.    
**INPUT_PULLUP**: Same effect as INPUT since some embedded boards doesn't have PULL resistos internally.  
**OUTPUT**: Sets GPIO pin number as output. 


Raspberry Pi BCM283x legacy modes:  
**RPI_INPUT**: Sets GPIO pin number as input using "/dev/mem" mapping.  
**RPI_INPUT_PULLDOWN**: Sets GPIO pin number as input and with a pull down resistor using "/dev/mem" mapping   
**RPI_INPUT_PULLUP**: Sets GPIO pin number as input and with a pull up resistor using "/dev/mem" mapping   
**RPI_OUTPUT**: Sets GPIO pin number as output using "/dev/mem" mapping.  
**RPI_PWM_OUTPUT**: Sets GPIO pin number as PWM "/dev/mem" mapping. (TODO add available pins for RPi)  
::: warning
Raspberry Pi BCM283x legacy modes only work in C++. 
:::

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