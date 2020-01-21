# Wire.beginTransmission()
Begin a transmission to the I2C slave device with the given address. Subsequently, queue bytes for transmission with the [write()](/i2c/write) function and transmit them by calling [endTransmission()](/i2c/endTransmission).

## Syntax 
```
Wire.beginTransmission(address)
``` 

## Parameters 

***address***:    
The 7-bit address of the device to transmit to.

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