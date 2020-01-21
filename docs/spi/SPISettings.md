# SPISettings
The SPISettings object is used to configure the SPI port for your SPI device. You can also configure the SPI separately see [SPI.setClockDivider()](/spi/setClockDivider),  [SPI.setBitOrder()](/spi/setBitOrder) and [SPI.setDataMode()](/spi/setDataMode) 

## Syntax 
```
// Javascript Format
settings = new linuxduino.SPISettings(speedMaximum, dataOrder, dataMode);
// C++ Format
SPISettings mySettting(speedMaximum, dataOrder, dataMode)
``` 

## Parameters 

***speedMaximum***:   
The maximum SPI clock speed.

*Available speeds*:   

**SPI_CLOCK_DIV2**: SPI clock to 8000000 (8 Mhz)   
**SPI_CLOCK_DIV4**: SPI clock to 4000000 (4 Mhz)   
**SPI_CLOCK_DIV8**: SPI clock to 2000000 (2 Mhz)   
**SPI_CLOCK_DIV16**: SPI clock to 1000000 (1 Mhz)   
**SPI_CLOCK_DIV32**: SPI clock to 500000 (500 khz)   
**SPI_CLOCK_DIV64**: SPI clock to 250000 (250 khz)   
**SPI_CLOCK_DIV128**: SPI clock to 125000 (125 khz)   

***dataOrder***:   
Data order when transmitting

*Available data orders*:  
**LSBFIRST**: Sends least significant bit first.   
**MSBFIRST**: Sends most significant bit first. 

***dataMode***:
Clock and Sampling configurations.

*Available data modes*:  
**SPI_MODE0**: Clock Idle low -> CPOL=0, First edge Sampling -> CPHA=0   
**SPI_MODE1**: Clock Idle low -> CPOL=0, Second edge Sampling -> CPHA=1    
**SPI_MODE2**: Clock Idle high -> CPOL=1, First edge Sampling -> CPHA=0   
**SPI_MODE3**: Clock Idle high -> CPOL=1, Second edge Sampling -> CPHA=1  

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