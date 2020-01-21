# Serial.flush()

## Syntax 
```
Serial.flush()
``` 

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write something on the other terminal (5 sec wait)...");
  linuxduino.delay(5000);

  // Memory allocation in js necessary
  let mem = new Buffer.alloc(10);

  //  Read 2 bytes
  var buff1 = Serial.readBytes(mem, 2);
  console.log("Recieved 1 = ", buff1);

  // Clear Serial buffer
  Serial.flush();

  //  Read 2 bytes (Should print nothing - flush)
  var buff2 = Serial.readBytes(mem, 2);
  console.log("Recieved 2 = ", buff2);

  Serial.end();
})();
```

Run it
```js
sudo node serial_flush.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial flush
int main(void) {

    // Memory allocation
    char buff[10];

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    printf("Write something on the other terminal (5 sec wait)...\n");
    delay(5000);

    //  Read 2 bytes
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 1 = %s\n", buff);

    // Clean buffer
    memset(buff, 0, sizeof(buff));

    // Clear Serial buffer
    Serial.flush();

    //  Read 2 bytes (Should print nothing - flush)
    Serial.readBytes(buff, 2);
    buff[2] = 0;
    printf("Recieved 2 = %s\n", buff);

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_flush.cpp -o serial_flush -llxduino
sudo ./serial_flush
```