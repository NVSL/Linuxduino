## Constants

General   

**LINUXDUINO_VERSION**: Shows the current Linuxduino version   
   
GPIO Operations  
   
**HIGH**: Equal to 1   
**LOW**: Equal to 0   
**INPUT**: Sets GPIO pin as input   
**OUTPUT**: Sets GPIO pin as output   
// GPIO Legacy constants     
**INPUT_PULLUP**: No effect same as input   
**INPUT_PULLDOWN**: No effect same as input   
(TODO ADD RPI_...)   

Serial Operations   

**DEC**: prints as decimal ascii text   
**HEX**: prints as hexadecimal ascii text   
**BIN**: prints as binary ascii text   
**OCT**: prints as octal ascii text   
**SERIAL_5N1**: Opens serial as -> data: 5 bits, partiy: None, stop bits: 1 bit    
**SERIAL_6N1**: Opens serial as -> data: 6 bits, partiy: None, stop bits: 1 bit   
**SERIAL_7N1**: Opens serial as -> data: 7 bits, partiy: None, stop bits: 1 bit   
**SERIAL_8N1**: Opens serial as -> data: 8 bits, partiy: None, stop bits: 1 bit   
**SERIAL_5N2**: Opens serial as -> data: 5 bits, partiy: None, stop bits: 2 bit   
**SERIAL_6N2**: Opens serial as -> data: 6 bits, partiy: None, stop bits: 2 bit   
**SERIAL_7N2**: Opens serial as -> data: 7 bits, partiy: None, stop bits: 2 bit   
**SERIAL_8N2**: Opens serial as -> data: 8 bits, partiy: None, stop bits: 2 bit   
**SERIAL_5E1**: Opens serial as -> data: 5 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_6E1**: Opens serial as -> data: 6 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_7E1**: Opens serial as -> data: 7 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_8E1**: Opens serial as -> data: 8 bits, partiy: Even, stop bits: 1 bit   
**SERIAL_5E2**: Opens serial as -> data: 5 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_6E2**: Opens serial as -> data: 6 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_7E2**: Opens serial as -> data: 7 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_8E2**: Opens serial as -> data: 8 bits, partiy: Even, stop bits: 2 bit   
**SERIAL_5O1**: Opens serial as -> data: 5 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_6O1**: Opens serial as -> data: 6 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_7O1**: Opens serial as -> data: 7 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_8O1**: Opens serial as -> data: 8 bits, partiy: Odd, stop bits: 1 bit   
**SERIAL_5O2**: Opens serial as -> data: 5 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_6O2**: Opens serial as -> data: 6 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_7O2**: Opens serial as -> data: 7 bits, partiy: Odd, stop bits: 2 bit   
**SERIAL_8O2**: Opens serial as -> data: 8 bits, partiy: Odd, stop bits: 2 bit   
   
SPI Operations    
   
**LSBFIRST**: Sends least significant bit first.   
**MSBFIRST**: Sends most significant bit first.   
**SPI_MODE0**: Clock Idle low -> CPOL=0, First edge Sampling -> CPHA=0   
**SPI_MODE1**: Clock Idle low -> CPOL=0, Second edge Sampling -> CPHA=1    
**SPI_MODE2**: Clock Idle high -> CPOL=1, First edge Sampling -> CPHA=0   
**SPI_MODE3**: Clock Idle high -> CPOL=1, Second edge Sampling -> CPHA=1  
**SPI_CLOCK_DIV2**: SPI clock to 8000000 (8 Mhz)   
**SPI_CLOCK_DIV4**: SPI clock to 4000000 (4 Mhz)   
**SPI_CLOCK_DIV8**: SPI clock to 2000000 (2 Mhz)   
**SPI_CLOCK_DIV16**: SPI clock to 1000000 (1 Mhz)   
**SPI_CLOCK_DIV32**: SPI clock to 500000 (500 khz)   
**SPI_CLOCK_DIV64**: SPI clock to 250000 (250 khz)   
**SPI_CLOCK_DIV128**: SPI clock to 125000 (125 khz)   


I2C (Wire) Operations 

**BUFFER_LENGTH**: Max I2C buffer available for transfers -> Set to 512 bytes.   

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Test digitalWrite
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var ledPin = 4; // Embedded board GPIO Number
  linuxduino.pinMode(ledPin, linuxduino.OUTPUT);
  console.log("Linuxduino Version:", linuxduino.LINUXDUINO_VERSION);
  while(1) {
    console.log("LED ON");
    linuxduino.digitalWrite(ledPin, linuxduino.HIGH);
    linuxduino.delay(1000); // Delay 1 sec
    console.log("LED OFF");
    linuxduino.digitalWrite(ledPin, linuxduino.LOW);
    linuxduino.delay(1000); // Delay 1 sec
  }
  return 0;
})();
```

Run it
```js
sudo node digitalWrite.js
```

### C++
```cpp
#include "Linuxduino.h"

// Test digitalWrite
int main(void) {
    int ledPin = 4; // Embedded board GPIO Number
    pinMode(ledPin, OUTPUT);
    printf("Linuxduino Version: %s\n", LINUXDUINO_VERSION);
    while(1) {
        printf("LED ON\n");
        digitalWrite(ledPin, HIGH);
        delay(1000); // Delay 1 sec
        printf("LED OFF\n");
        digitalWrite(ledPin, LOW);
        delay(1000); // Delay 1 sec
    }
    return 0;
}
```

Run it
```sh
g++ digitalRead.cpp -o digitalRead -llxduino
sudo ./digitalRead
```
