# SPI.set*()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing SPI separate settings
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  // Open SPI port
  SPI = new linuxduino.SPI();
  SPI.begin("/dev/spidev0.0");

  // Set SPI Settings
  SPI.setClockDivider(linuxduino.SPI_CLOCK_DIV64);
  SPI.setBitOrder(linuxduino.MSBFIRST);
  SPI.setDataMode(linuxduino.SPI_MODE3);

  // Send Hello World! every second
  buff = Buffer.from("Hello World!\n");
  var ret;
  while(1) {
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously. 
    for(var i=0; i<buff.length; i++) {
      ret = SPI.transfer(buff[i]); // Transmit and receive one byte
      process.stdout.write(String.fromCharCode(ret));
    }
    process.stdout.write('\n');
    linuxduino.delay(1000); // delay 1 sec.
  }

  SPI.end();
})();
```

Run it
```js
sudo node spi_setSettings.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing SPI separate settings
int main(void) {

    char ret;

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    // Send Hello World! every second
    while(1) {
        // Note in SPI the last character will not be printed here. 
        // In SPI you recieve what you sent previously. 
        for (const char *p = "Hello World!\n" ; *p!=0 ; p++) {
            ret = SPI.transfer(*p); // Transmit and receive one byte
            printf("%c", ret);
        }
        printf("\n");
        delay(1000); // delay 1 sec.
    }

    SPI.end(); 
    return 0;
}
```

Run it
```sh
g++ spi_setSettings.cpp -o spi_setSettings -llxduino
sudo ./spi_setSettings
```