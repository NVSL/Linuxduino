# Serial.write()


## Example

Make a note about Serial.write_byte

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial writes
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var buff = "Hello World";

  if(Serial) { // This is just to test (if(Serial))
      Serial.write('A');
      Serial.write("Lol");
      Serial.write(buff, buff.length);
      Serial.write_byte(0x41); // Sends explicit byte
      Serial.write('\r');
      Serial.write('\n');
  }

  Serial.end();
})();
```

Run it
```js
sudo node serial_write.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial writes
int main(void) {

    char buff[] = "Hello World";

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200, SERIAL_8N1);

    if(Serial) { // This is just to test (if(Serial))
        Serial.write('A');
        Serial.write("Lol");
        Serial.write(buff, strlen(buff));
        Serial.write(0x41); // Sends explicit byte
        Serial.write('\r');
        Serial.write('\n');
    }

    Serial.end();

    return 1;
}
```

Run it
```sh
g++ serial_write.cpp -o serial_write -llxduino
sudo ./serial_write
```