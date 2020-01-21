# SPI.endTransaction()
Currently this function does nothing, kept for legacy.

## Syntax 
```
SPI.endTransaction()
``` 

## Parameters
None

## Returns
None 

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing SPI beginTransaction
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  // Open SPI port
  SPI = new linuxduino.SPI();
  SPI.begin("/dev/spidev0.0");

  // Set SPI Settings
  settingsA = new linuxduino.SPISettings(linuxduino.SPI_CLOCK_DIV64, 
    linuxduino.MSBFIRST, linuxduino.SPI_MODE3);

  // Send Hello World! every second
  buff = Buffer.from("Hello World!\n");
  var ret;
  while(1) {
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously. 
    for(var i=0; i<buff.length; i++) {
      ret = SPI.transfer(buff[i]); // Transmit and receive one byte
      process.stdout.write(String.fromCharCode(ret));
    }
    SPI.endTransaction();
    process.stdout.write('\n');
    linuxduino.delay(1000); // delay 1 sec.
  }
  
  SPI.end();
})();
```

Run it
```js
sudo node spi_beginTransaction.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing SPI beginTransaction
int main(void) {

    char ret;

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPISettings settingsA(SPI_CLOCK_DIV64, MSBFIRST, SPI_MODE3);

    // Send Hello World! every second
    while(1) {
        SPI.beginTransaction(settingsA);
        // Note in SPI the last character will not be printed here. 
        // In SPI you recieve what you sent previously. 
        for (const char *p = "Hello, world!\n" ; *p!=0 ; p++) {
            ret = SPI.transfer (*p); // Transmit and receive one byte
            printf("%c", ret);
        }
        SPI.endTransaction();
        printf("\n");        
        delay(1000); // delay 1 sec.
    }

    SPI.end(); 
    return 0;
}

```

Run it
```sh
g++ spi_beginTransaction.cpp -o spi_beginTransaction -llxduino
sudo ./spi_beginTransaction
```