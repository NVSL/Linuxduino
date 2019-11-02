# Getting Started 

Linuxduino is a port of the [Arduino Programing language](https://www.arduino.cc/reference/en/) for embedded systems running Linux (e.g., [Raspberry PI](https://www.raspberrypi.org/), [DragonBoard 410c](https://www.96boards.org/product/dragonboard410c/), even your own Linux Computer). Linuxduino is a C++ library and has been ported to JavaScript using [WebAssembly](https://webassembly.org/). 

## Install 

### JavaScript
::: warning
linuxduino requires Node v8 or above
:::
```sh
npm install linuxduino
```

### C++
```sh
todo
```

## Usage 

### Serial 
```js
const linuxduino = require('linuxduino');

(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port /dev/ttyUSB at 115200 baud
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);
    
  // Write something
  Serial.println("Hello World");
})();
```

## Electron compatibility

