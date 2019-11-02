# Serial.peek()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial peek
// peek, -1 when nothing and afected by timeOut 
// Checks the next char of the serial without removing it.
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var peekChar;
      
  // Note: peek should not block.
  console.log("Write Something...");
  linuxduino.delay(5000);
  peekChar = Serial.peek();
  console.log("Your next char is = ", String.fromCharCode(peekChar));

  Serial.end();
})();
```

Run it
```js
sudo node serial_peek.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial peek
// peek, -1 when nothing and afected by timeOut 
// Checks the next char of the serial without removing it.
int main(void) {

    char peekChar;

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
        
    // Note: peek should not block.
    printf("Write Something...\n");
    delay(5000);
    peekChar = Serial.peek();
    printf("Your next char is = %c\n", peekChar);

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_peek.cpp -o serial_peek -llxduino
sudo ./serial_peek
```