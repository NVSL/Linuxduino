# Serial.find()


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

  console.log("Waiting to recieve OK ('OK' will trigger a found message)...");
  Serial.setTimeout(5000); // Wait 5 seconds
  while (1) {
    var isOKFound = false;

    // If target OK found return true, if timeout return false
    isOKFound = Serial.find("OK");    //Wait for 'OK' for 5 sec
    if (isOKFound) {
        console.log("OK found");
    } else {
        console.log("Noting found");
    }

    Serial.flush();

    console.log("Time OVER");
  }

  Serial.end();
})();
```

Run it
```js
sudo node serial_find.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial find
int main(void) {

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);

    printf("Waiting to recieve OK ('OK' will trigger a found message)...\n");
    Serial.setTimeout(5000); // Wait 5 seconds
    while (1) {
        bool isOKFound = false;

        // If target OK found return true, if timeout return false
        isOKFound = Serial.find("OK");    //Wait for 'OK' for 5 sec
        if (isOKFound) {
            printf("OK found\n");
        } else {
            printf("Noting found\n");
        }

        Serial.flush();

        printf("Time OVER\n");
    }

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_find.cpp -o serial_find -llxduino
sudo ./serial_find
```