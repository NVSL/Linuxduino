# Serial.print() & Serial.println()

## Syntax 
```
Serial.print(str)
Serial.print(n, base)
(extra) Serial.print_byte(byte) // JavaScript only
``` 
*Serial.println() is the same but adds a new line at the end.   

::: info   
Serial.print_byte() is only available for JavaScript and enables sending byte data directly.
:::

## Parameters

***str***:   

***n***: 

***base***: 

*Available bases*:   
**DEC**: prints as decimal ascii text   
**HEX**: prints as hexadecimal ascii text   
**BIN**: prints as binary ascii text   
**OCT**: prints as octal ascii text  

***byte***:   


## Returns


## Example

Make a note about Serial.print_byte

### Javascript 
```js
const linuxduino = require('linuxduino');

// Testing Serial print, println, printf
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

	var message = "A char message";
  
  // Printf 
  // (Not possible in JS since embind doesn't support multiple args loader)

  // Print
  Serial.print("A const char message ");
  Serial.print("(no new line)");
  Serial.println("A const char message ");
  Serial.println("(new line)");
  Serial.print(message);
  Serial.println(message);

  // Println
  Serial.println(15, linuxduino.DEC);
  Serial.println(15, linuxduino.OCT);
  Serial.println(15, linuxduino.HEX);
  Serial.println(15, linuxduino.BIN);
  Serial.println(-15, linuxduino.DEC);
  Serial.println(-15, linuxduino.OCT);
  Serial.println(-15, linuxduino.HEX);
  Serial.println(-15, linuxduino.BIN);

  // **Added for javascript (Sends explicit byte)
  Serial.print_byte(0x41);    // Sends ascii A
  Serial.println_byte(0x42);  // Sends ascii B


  Serial.end();
})();
```

Run it
```js
sudo node serial_parse.js
```

### C++
```cpp
#include "Linuxduino.h"

// Testing Serial print, println, printf
int main(void) {

	char message[] = "A char message";

    // Open Serial
    Serial.begin("/dev/ttyUSB0", 115200);
    
    // Printf
    Serial.printf("\n\r ---- Testing printf, print, println ----- \n\r");
    Serial.printf("Integer = %d, Float = %f, Char = %c, String = %s \n\r", 
                10, 3.1416, 'a', "Hello World");

    // Print
    Serial.print("A const char message ");
    Serial.print("(no new line)");
    Serial.println("A const char message ");
    Serial.println("(new line)");
    Serial.print(message);
    Serial.println(message);

    // Println
    Serial.println(15, DEC);
    Serial.println(15, OCT);
    Serial.println(15, HEX);
    Serial.println(15, BIN);
    Serial.println(-15, DEC);
    Serial.println(-15, OCT);
    Serial.println(-15, HEX);
    Serial.println(-15, BIN);

    // Send explicit byte
    Serial.print(0x41);    // Sends ascii A
    Serial.println(0x42);  // Sends ascii B

    Serial.end();

    return 0;
}
```

Run it
```sh
g++ serial_print.cpp -o serial_print -llxduino
sudo ./serial_print
```