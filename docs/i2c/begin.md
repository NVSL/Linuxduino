# Wire.begin()
Initiate the I2C bus as master. Slave option is not supported yet.  

## Syntax 
```
Wire.begin() // Only available with setWire()
(!) Wire.begin(address) // Not available, I2C in slave mode not supported
(extra) Wire.begin(i2cDeviceName)
```
* See [setWire()](/i2c/getset)

## Parameters 

***i2cDeviceName***:    
The linux i2c device path (e.g., "/dev/i2c-1").

## Returns 
None

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing I2C write
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var world = new Buffer("World");
  
  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin("/dev/i2c-1");
  
  // Send Hello World! to device
  Wire.beginTransmission(8); // 7-bit device I2C address
  Wire.write("Hello");
  Wire.write(" ");
  Wire.write(world, world.length);
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
sudo node i2c_write.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing I2C write
int main(void) {

    char world[] = "World";

    Wire.begin("/dev/i2c-1");

    // Send Hello World! to device
    Wire.beginTransmission(8); // 7-bit device I2C address
    Wire.write("Hello");
    Wire.write(' ');
    Wire.write(world, strlen(world));
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
g++ i2c_write.cpp -o i2c_write -llxduino
sudo ./i2c_write
```