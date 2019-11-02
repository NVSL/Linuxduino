# Serial.read()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial read and available
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var incomingByte;
  var availableBytes;
    
  console.log("Write Something...");
  linuxduino.delay(5000);

  // Check if there is available data:
  if ((availableBytes = Serial.available()) > 0) {

    console.log("Available bytes = ", availableBytes);

    for (var i=0; i<availableBytes; i++) {
        // read incoming byte:
        incomingByte = Serial.read();
        // print incoming byte:
        console.log(`Incoming Byte ${i}: ${String.fromCharCode(incomingByte)}`);
    }

  } else {
      console.log("Nothing available");
  }

  Serial.end();
})();
```

Run it
```js
sudo node serial_read.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial read and available
int main(void) {

    char incomingByte;
    int availableBytes;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);
    
    printf("Write Something...\n");
    delay(5000);

    // Check if there is available data:
    if ((availableBytes = Serial.available()) > 0) {

        printf("Available bytes = %d\n", availableBytes);

        for (int i=0; i<availableBytes; i++) {
            // read incoming byte:
            incomingByte = Serial.read();
            // print incoming byte:
            printf("Incoming Byte %d: %c \n", i, incomingByte);
        }

    } else {
        printf("Nothing available \n");
    }

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_read.cpp -o serial_read -llxduino
sudo ./serial_read
```