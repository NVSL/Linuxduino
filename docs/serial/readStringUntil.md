# Serial.readStringUntil()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial readStringUntil
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var data = "";

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write Something (reads until letter x or timeout of 5 sec)...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  data = Serial.readStringUntil('x');
  console.log("Recieved data = ",data);

  Serial.end();
})();
```

Run it
```js
sudo node serial_readStringUntil.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial readStringUntil
int main(void) {

    String data = "";

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write Something (reads until letter x or timeout of 5 sec)...\n");

    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    data = Serial.readStringUntil('x');
    printf ("Recieved data = %s \n",data.c_str());

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_readStringUntil.cpp -o serial_readStringUntil -llxduino
sudo ./serial_readStringUntil 
```