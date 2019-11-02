# setSerial() & getSerial()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
	linuxduino.setSerial("/dev/ttyUSB0");
	Serial.begin(115200);

	console.log("Current Serial Driver = ", linuxduino.getSerial());
	console.log("Sending Hello World...");
	Serial.println("Hello World");
	Serial.end();

	return 0;
})();
```

Run it
```js
sudo node serial_getset.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial setSerial and getSerial
int main(void) {

    // Open Serial port
    setSerial("/dev/ttyUSB0");
    Serial.begin(115200);

    printf("Current Serial Driver = %s \n", getSerial());
    printf("Sending Hello World...\n");
    Serial.println("Hello World");
    Serial.end();

    return 0;
}
```

Run it
```sh
g++ serial_getset.cpp -o serial_getset -llxduino
sudo ./serial_getset
```