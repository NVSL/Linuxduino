# Wire.write()
Writes data from a slave device in response to a request from a master, or queues bytes for transmission from a master to slave device (in-between calls to beginTransmission() and endTransmission()).

## Syntax 
```
Wire.write(string)
Wire.write(data, length)
Wire.write(value) // C++ only
(extra) Wire.write_byte(value) // Javascript only
``` 

:::tip 
For sending raw bytes values (e.g., 0x41) use **Wire.write_byte()** in Javascript
:::

## Parameters 
***value***:    
A value to send as a single byte. See fortmats for C++ and JavaScript

***string***:    
A string to send as a series of byte.

***data***:   
An array of data to send as bytes.

***length***:   
The number of bytes to transmit.

## Returns

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
  Wire.write_byte(0x57); // W Ascii
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
    Wire.write(0x57); // W Ascii
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