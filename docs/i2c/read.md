# Wire.read()
Reads a byte that was transmitted from a slave device to a master after a call to [requestFrom()](/i2c/requestFrom) or was transmitted from a master to a slave.

## Syntax 
```
Wire.read()
``` 

## Parameters 
None

## Returns
The next byte received.

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing I2C write
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin("/dev/i2c-1");

  Wire.requestFrom(8, 6);           // Request 6 bytes from slave device #8

  var available = Wire.available(); // Check available bytes sent from slave device
  console.log("Bytes available = ", available);
  if (available == 0 ) {            // Make sure we have communication with the device.
    console.log("Wrong I2C address or I2C wires may not be connected properly");
    return -1;
  }
  process.stdout.write("Message recieved = ");
  while (Wire.available()) {        
    var c = Wire.read();            // Read bytes as character
    process.stdout.write(String.fromCharCode(c));
  }
  console.log("");

  Wire.end();
  return 1;
})();
```

Run it
```js
sudo node i2c_read.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing I2C read
int main(void) {

    Wire.begin("/dev/i2c-1");

    Wire.requestFrom(8, 6);           // Request 6 bytes from slave device #8

    int available = Wire.available(); // Check available bytes sent from slave device
    printf("Bytes available = %d \n", available);
    if (available == 0 ) {            // Make sure we have communication with the device.
        printf("Wrong I2C address or I2C wires may not be connected properly\n");
        return -1;
    }
    printf("Message recieved = ");
    while (Wire.available()) {
        char c = Wire.read();         // Read bytes as character
        printf("%c", c);
    }
    printf("\n");

    Wire.end();
    return 1;
}
```

Run it
```sh
g++ i2c_read.cpp -o i2c_read -llxduino
sudo ./i2c_read
```