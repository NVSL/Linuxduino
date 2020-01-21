# Serial.readBytes()

## Syntax 
```
Serial.readBytes(buffer, length)
``` 
## Parameters 

***buffer***:   

***length***:   


## Returns

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial readBytes
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var buff = Buffer.alloc(10);

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);
    
  console.log("Write Something (Recieves max 5 bytes)...");
  linuxduino.delay(5000);

  // Clean buffer
  buff.fill(0);

  //  Read 5 bytes
  buff = Serial.readBytes(buff, 5);
  console.log("Recieved = ", buff);

  Serial.end();
})();
```

Run it
```js
sudo node serial_readBytes.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial readBytes
int main(void) {

    char buff[10];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    printf("Write Something (Recieves max 5 bytes)...\n");
    delay(5000);

    // Clean buffer
    for (int i = 0; i<10; i++) {
        buff[i] = 0;
    }

    //  Read 5 bytes
    Serial.readBytes(buff, 5);
    buff[5] = 0;
    printf("Recieved = %s\n", buff);

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_readBytes.cpp -o serial_readBytes -llxduino
sudo ./serial_readBytes
```