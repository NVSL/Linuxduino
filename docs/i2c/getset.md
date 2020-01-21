# (extra) setWire() & getWire()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing set/get I2C device name
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  linuxduino.setWire("/dev/i2c-1");
  console.log("Current I2C Driver = ", linuxduino.getWire());

  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin(); 

  Wire.beginTransmission(8); // 7-bit device I2C address
  Wire.write("Hello World");
  var bytes_transmitted = Wire.endTransmission();
  // Make sure transmission was sucessful
  if (bytes_transmitted == 0 ) {
    console.log("Wrong I2C address or I2C wires may not be connected properly");
    return -1;
  }
  console.log("Hello World msg sent!");

  Wire.end(); 
  return 1;
})();
```

Run it
```js
sudo node i2c_getset.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing set/get I2C device name
int main(void) {

    setWire("/dev/i2c-1");
    printf("Current I2C Driver = %s \n", getWire());

    // Open I2C port
    Wire.begin(); 

    Wire.beginTransmission(8); // 7-bit device I2C address
    Wire.write("Hello World");
    int bytes_transmitted = Wire.endTransmission();
    // Make sure transmission was sucessful
    if (bytes_transmitted == 0 ) {
        printf("Wrong I2C address or I2C wires may not be connected properly\n");
        return -1;
    }
    printf("Hello World msg sent! \n");

    Wire.end();
    return 1;
}
```

Run it
```sh
g++ i2c_getset.cpp -o i2c_getset -llxduino
sudo ./i2c_getset
```