# Serial.readStringCommand()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial readStringCommand
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write something...");

  // Read string and wait for "enter"
  // Works as a termial (Ctrl^C to terminate)
  while(1) {
      var data = Buffer.alloc(50);
      data.fill(0);
      //  Read
      data = Serial.readStringCommand('\r', data, data.length);
      console.log("Recieved = ", data);
  }

  Serial.end();
})();
```

Run it
```js
sudo node serial_readStringCommand.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial readStringCommand
int main(void) {

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write something...\n");

    // Read string and wait for "enter"
    // Works as a termial (Ctrl^C to terminate)
    while(1) {
        char data[50];
        memset(data, 0, sizeof(data));
        //  Read
        Serial.readStringCommand('\r', data, sizeof(data));
        printf ("Recieved = %s\n", data);
    }

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_readStringCommand.cpp -o serial_readStringCommand -llxduino
sudo ./serial_readStringCommand 
```