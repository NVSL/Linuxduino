# SPI.transfer()
Transfer and recieve a single byte or an array of data which is stored in a buffer. 

## Syntax 
```
receivedVal = SPI.transfer(val)
SPI.transfer(buffer, size) // C++ Format
recivedBuff = SPI.transfer(buffer, size) // JavaScript Format
``` 
:::warning
SPI.transfer16() currently hasn't been implemented
:::

## Parameters 

***val***:   
The byte to send out over the bus   

***buffer***:   
The array of data to be transferred   

***size***:   
Number of bytes to transfer   


## Returns 
The received data

## Example

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing spi transfer()
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

  // Test transfer(buffer, len)
  var msg = "Hello World!\n";
  var rx = SPI.transfer(msg, msg.length);   // Send Hello World!\n
  process.stdout.write("Data Recieved = "); 
  for (var i=0; i<rx.length; i++){
      process.stdout.write(rx.charAt(i));
  }
  process.stdout.write("\n");

  // Test transfer(buffer, len)
  var msg2 = Buffer.from([0x41, 0x0A]);
  var rx = SPI.transfer(msg2, msg2.length);   // Send A\n
  process.stdout.write("Data Recieved = "); 
  for (var i=0; i<rx.length; i++){
      process.stdout.write(rx.charAt(i));
  }
  process.stdout.write("\n");


  // Test transfer(byte)
  var ret; 
  ret = SPI.transfer(0x42); // Send 'B'
  console.log("Data Recieved = "+String.fromCharCode(ret));
  ret = SPI.transfer(0x0A); // Send '\n'
  console.log("Data Recieved = "+String.fromCharCode(ret));

  SPI.end(); 
})();
```

Run it
```js
sudo node spi_transfer.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing spi transfer()
int main(void) {

    // Open SPI port
    SPI.begin("/dev/spidev0.0");

    // Set SPI Settings
    SPI.setClockDivider(SPI_CLOCK_DIV64);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);

    // Test transfer(buffer, len)
    char msg[] = "Hello World!\n";
    SPI.transfer(msg, strlen(msg)); // Send Hello World!\n
    printf("Data Recieved = ");
    for (unsigned int i=0; i<strlen(msg); i++){
         printf("%c",msg[i]);
    }
    printf("\n");

    // Test transfer(buffer, len)
    char msg2[2] = {0x41, 0x0A};
    SPI.transfer(msg2, 2); // Send A\n
    printf("Data Recieved = ");
    for (unsigned int i=0; i<strlen(msg); i++){
         printf("%c",msg[i]);
    }
    printf("\n");

    // Test transfer(byte)
    char ret;
    ret = SPI.transfer(0x42); // Send 'B'
    printf("Data Recieved = %c\n", ret);
    ret = SPI.transfer(0x0A); // Send '\n'
    printf("Data Recieved = %c\n", ret);

    SPI.end(); 
    return 1;
}
```

Run it
```sh
g++ spi_transfer.cpp -o spi_transfer -llxduino
sudo ./spi_transfer
```