## bit() 
## bitClear() 
## bitRead() 
## bitSet() 
## bitWrite() 
## highByte() 
## lowByte() 

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Test BITS AND BYTES functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var value;

  // bit(1)
  console.log("0x02 & bit(1) = ", (0x02 & linuxduino.bit(1)));
  // bitClear()
  value = 0x02;
  linuxduino.bitClear(value, 1);
  console.log("bitClear(0x02, 1) = ", value);
  // bitRead() 
  console.log("bitRead(0x02, 1) = ", linuxduino.bitRead(0x02, 1));
  // bitSet()
  value = 0x00;
  linuxduino.bitSet(value, 1);
  console.log("bitSet(0x00, 1) = ", value);
  // bitWrite()
  value = 0x00; 
  linuxduino.bitWrite(value, 0, 1);
  console.log("bitWrite(0x00, 0, 1) = ", value);
  // highByte()
  console.log("highByte(0xABCD) = ", linuxduino.highByte(0xABCD).toString(16).toUpperCase());
  // lowByte()
  console.log("lowByte(0xABCD) = ", linuxduino.lowByte(0xABCD).toString(16).toUpperCase());

})();
```

Run it
```js
node bitsAndBytes.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test BITS AND BYTES functions
int main(void) {

    unsigned char value;

    // bit(1)
    printf("0x02 & bit(1) = %X \n", (unsigned char) (0x02 & bit(1)));
    // bitClear()
    value = 0x02;
    bitClear(value, 1);
    printf("bitClear(0x02, 1) = %X \n", value);
    // bitRead() 
    printf("bitRead(0x02, 1) = %X \n", bitRead(0x02, 1));
    // bitSet()
    value = 0x00;
    bitSet(value, 1);
    printf("bitSet(0x00, 1) = %X \n", value);
    // bitWrite()
    value = 0x00; 
    bitWrite(value, 0, 1);
    printf("bitWrite(0x00, 0, 1) = %X \n", value);
    // highByte()
    printf("highByte(0xABCD) = %X \n", highByte(0xABCD));
    // lowByte()
    printf("lowByte(0xABCD) = %X \n", lowByte(0xABCD));

    return 1;
}
```

Run it
```sh
g++ bitsAndBytes.cpp -o bitsAndBytes -llxduino
./bitsAndBytes
```