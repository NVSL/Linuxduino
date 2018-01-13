# Linuxduino.js
A javscript library for communicating with hardware in a Arduino style programming for any Linux platform.

**Note**: This library is currently in Beta.   
This library is intended to be used with **Node >= v8.0.0** and **Electron (Todo version)**. 

# Install
```bash
npm install linuxduino 
```

# Basics 
The linuxduino library was built using webassembly and thus it requires a little extra code to know when the webassembly (wasm) binary has been loaded. 

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Your linuxduino code
}
```

# GPIO

Currenlty webassembly doesn't support pthreads which is required for inputs (e.g. ```pinMode(..., INPUT)```), but is under development. This is the main reason this library is still in Beta. For outputs (e.g. blinking an LED) here is an example for raspberry pi: 

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    var ledPin = 4; // RPi GPIO4
    Linuxduino.pinMode(ledPin, Linuxduino.OUTPUT);
    while (1) {
    	console.log("LED ON");
    	Linuxduino.digitalWrite(ledPin, 1); // Turn on LED
    	Linuxduino.delay(1000); // Delay 1 sec
    	console.log("LED OFF");
    	Linuxduino.digitalWrite(ledPin, 0); // Turn off LED
    	Linuxduino.delay(1000); // Delay 1 sec
    }
}
```

# Serial

For communicating with a Serial port in linux you need to know it's device path and name (e.g. **/dev/ttyUSB0**). There are two ways for setting the device name and path:

First, using setSerial("/dev/..."):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Set serial device name
    Linuxduino.setSerial("/dev/ttyUSB0");
    console.log(Linuxduino.getSerial());
    
    // Open serial
    Serial =  new Linuxduino.Serial();
    Serial.begin(9600);
    
    // Write something
    Serial.println("Hello World");
    
}
```

Second, directly Serial.begin("/dev/...", 9600):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Open serial
    Serial =  new Linuxduino.Serial();
    Serial.begin("/dev/ttyUSB0", 9600);
    
    // Write something
    Serial.println("Hello World");
 
}
```

# SPI 

For communicating with a SPI port in linux you need to know it's device path and name (e.g. **/dev/spidev0.0**). There are two ways for setting the device name and path:

First, using setSPI("/dev/..."):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
     // Set SPI device name
    Linuxduino.setSPI("/dev/spidev0.0");
    console.log(Linuxduino.getSPI());
    
    // Open SPI port
    settingsA = new Linuxduino.SPISettings(Linuxduino.SPI_CLOCK_DIV64, 
        Linuxduino.MSBFIRST, Linuxduino.SPI_MODE3);
    SPI =  new Linuxduino.SPI();
    SPI.begin();
    
    // Send Hello World to SPI device and listen for received data every second
    buff = new Buffer("Hello World\n");
    var ret;
    while(1) {
    	SPI.beginTransaction(settingsA);
    	for(var i=0; i<buff.length; i++) {
    		ret = SPI.transfer(buff[i]); // Transmit and receive one byte
    		process.stdout.write(String.fromCharCode(ret));
    	}
    	process.stdout.write('\n');
    	SPI.endTransaction();
    	Linuxduino.delay(1000);
    }
    SPI.end();
    
}
```

Second, directly in SPI.begin("/dev/..."):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Open SPI port
    settingsA = new Linuxduino.SPISettings(Linuxduino.SPI_CLOCK_DIV64, 
        Linuxduino.MSBFIRST, Linuxduino.SPI_MODE3);
    SPI =  new Linuxduino.SPI();
    SPI.begin("/dev/spidev0.0");
    
    // Your SPI code
    
}
```

# Wire (I2C) 

For communicating with a I2C port in linux you need to know it's device path and name (e.g. **/dev/i2c-1**). There are two ways for setting the device name and path:

First, using setI2C("/dev/..."):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Set I2C device name
    Linuxduino.setWire("/dev/i2c-1");
    console.log(Linuxduino.getWire());
    
    // Open I2C port
    Wire = new Linuxduino.Wire();
    Wire.begin();
    
    // Send Hello World! to device
    Wire.beginTransmission(8); // 7-bit device address
    Wire.write("Hello");
    Wire.write(" ");
    var world = new Buffer("World!");
    Wire.write(world, world.length);
    Wire.endTransmission();
    Wire.end();
    
}
```

Second, directly in Wire.begin("/dev/..."):

```javascript 
var Linuxduino = require("linuxduino");

Linuxduino.onRuntimeInitialized = function() {
    console.log('wasm file loaded');
    
    // Open I2C port
    Wire = new Linuxduino.Wire();
    Wire.begin("/dev/i2c-1");
    
    // Send Hello World! to device
    Wire.beginTransmission(8); // 7-bit device address
    Wire.write("Hello");
    Wire.write(" ");
    var world = new Buffer("World!");
    Wire.write(world, world.length);
    Wire.endTransmission();
    Wire.end();
    
}
```

Note, if you want to send exactly one byte in I2C for example 0xFF you need to use ```Wire.write_byte(0xFF)```.  


# List of Implemented Funtions
TODO

# Support for Electron
TODO



