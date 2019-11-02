# Serial.readString()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial readString
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var data = "";

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write Something...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  // Read data as string until timeout 
  data = Serial.readString();
  console.log("Recieved data = ", data);

  Serial.end();
})();
```

Run it
```js
sudo node serial_readString.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial readString
int main(void) {

    String data = ""; // You can use std:string or char *
    
    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Write Something...\n");

    Serial.setTimeout(5000);  // Set timeout of 5 seconds

    // Read data as string until timeout 
    data = Serial.readString();
    printf ("Recieved data = %s \n",data.c_str());

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_readString.cpp -o serial_readString -llxduino
sudo ./serial_readString 
```