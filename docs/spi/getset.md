# setSPI() & getSPI()


## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing SPI set/get
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
    
    // Set SPI device name
    linuxduino.setSPI("/dev/spidev0.0");
    console.log(linuxduino.getSPI());

    // Open SPI port
    SPI = new linuxduino.SPI();
    SPI.begin();

    // Set SPI Settings
    settingsA = new linuxduino.SPISettings(linuxduino.SPI_CLOCK_DIV64, 
        linuxduino.MSBFIRST, linuxduino.SPI_MODE3);
    
    // Send Hello World!
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously.
    var msg = Buffer.from("Hello World!\n")
    for (var i = 0; i < msg.length ; i++) {
        ret = SPI.transfer(msg[i]);
        process.stdout.write(String.fromCharCode(ret));
    }
    SPI.endTransaction();
    process.stdout.write('\n');
    
    SPI.end();
})();
```

Run it
```js
sudo node spi_getset.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing SPI set/get
int main(void) {

    char ret;

    setSPI("/dev/spidev0.0");
    printf("Current SPI Driver = %s \n", getSPI());

    // Open SPI port
    SPI.begin();

    // Set SPI Settings
    SPISettings settingsA(SPI_CLOCK_DIV64, MSBFIRST, SPI_MODE3);

    // Send Hello World!
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously. 
    for (const char *msg = "Hello World!\n" ; *msg!=0 ; msg++) {
        ret = SPI.transfer(*msg);
        printf("%c", ret);
    }
    SPI.endTransaction();
    printf("\n");
    
    SPI.end(); 
    return 1;
}
```

Run it
```sh
g++ spi_getset.cpp -o spi_getset -llxduino
sudo ./spi_getset
```