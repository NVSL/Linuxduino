# Serial.readBytesUntil()

## Syntax 
```
Serial.readBytesUntil(terminator, buffer, length)
``` 
## Parameters 

***terminator***:   

***buffer***:   

***length***:   


## Returns

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial readBytesUntil, setTimeout
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var buff = Buffer.alloc(100);

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);
    
  console.log("Write Something (reads until letter x or timeout of 5 sec)...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  // Clean buffer
  buff.fill(0);

  // Read bytes until x is found or timeout
  buff = Serial.readBytesUntil('x', buff, 100);
  console.log("Recieved = ", buff);

  Serial.end();
})();
```

Run it
```js
sudo node serial_readBytesUntil.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial readBytesUntil, setTimeout
int main(void) {

    char buff[100];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    printf("Write Something (reads until letter x or timeout of 5 sec)...\n");

    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    // Clean buffer
    for (int i = 0; i<10; i++) {
        buff[i] = 0;
    }

    // Read bytes until x is found or timeout
    Serial.readBytesUntil('x', buff, 100);
    buff[99] = 0;
    printf("Recieved = %s\n", buff);

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_readBytesUntil.cpp -o serial_readBytesUntil -llxduino
sudo ./serial_readBytesUntil
```