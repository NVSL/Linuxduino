# Getting Started 

Linuxduino is a port of the [Arduino Programing language](https://www.arduino.cc/reference/en/) for embedded systems running Linux (e.g., [Raspberry PI](https://www.raspberrypi.org/), [DragonBoard 410c](https://www.96boards.org/product/dragonboard410c/), even your own Linux Computer). Linuxduino is a C++ library and has been ported to JavaScript using [WebAssembly](https://webassembly.org/). 

## Install 

### JavaScript
::: warning
linuxduino requires Node v8 or above
:::
```sh
npm install linuxduino
```

### C++
```sh
todo
```

## Usage 

### Blink an LED in Javascript 
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

### Blink an LED in C++ 
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

Check the [Reference](/reference/) to see the full list of implemented functions and examples. 

## Arduino style compatibility for C++

C++ programs can also use the Arduino programming style by including the 
```Arduino.h``` instead of ```Linuxduino.h``` header and compiling them 
with ```-llxarduino``` instad of ```-llxduino```. Example:

### Blink an LED in C++ using the Arduino programming style.
```cpp
#include "Arduino.h"

// Test Arduino style digitalWrite

int ledPin = 4; // GPIO4

void setup () {
    pinMode(ledPin, OUTPUT);
}

void loop () {
    printf("LED ON\n");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    printf("LED OFF\n");
    digitalWrite(ledPin, LOW);
    delay(1000);
}
```

Run it
```sh
g++ digitalWrite.cpp -o digitalWrite -llxarduino
sudo ./digitalWrite
```

Note that ```Wire.h``` and ```SPI.h``` should be included separately if ```Arduino.h``` is used. 


## Electron compatibility

