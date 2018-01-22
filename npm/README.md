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

# I/O

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

**Digital I/O**  

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| pinMode(pin, mode)  | :heavy_check_mark: | :heavy_check_mark: |
| digitalWrite(pin, value) | :heavy_check_mark: | :heavy_check_mark: |
| digitalRead(pin)  | :heavy_check_mark: | :x: --Waiting for pthreads |

**Analog I/O**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| analogReference(type) | :x: -- No hardware support | :x:  |
| analogRead(pin) | :x: -- No hardware support | :x: |
| analogWrite(pin, value) - PWM | :heavy_check_mark: | :x: --Waiting for pthreads |
| (EXTRA) setPwmDutyCycle (pin, dutycycle)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| (EXTRA) setPwmFrequency (pin, frequency, dutycycle)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| (EXTRA) setPwmFrequency (pin, frequency)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| (EXTRA) setPwmPeriod (pin, microseconds)  | :heavy_check_mark: | :x: --Waiting for pthreads |
 
**Advanced I/O**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| tone(pin, frequency)   | :heavy_check_mark: | :x: --Waiting for pthreads |
| tone(pin, frequency, duration) | :heavy_check_mark: | :x: --Waiting for pthreads |
| noTone(pin)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| shiftOut(dataPin, clockPin, bitOrder, value)  | :heavy_check_mark: | :heavy_check_mark: |
| byte incoming = shiftIn(dataPin, clockPin, bitOrder) | :heavy_check_mark: | :heavy_check_mark: |
| pulseIn(pin, value)  | :heavy_check_mark: | :heavy_check_mark: |
| pulseIn(pin, value, timeout) | :heavy_check_mark: | :heavy_check_mark: |

**Serial**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| if (Serial)  | :heavy_check_mark: | :x: |
| Serial.available() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.availableForWrite() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.begin(speed) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.begin(speed, config)| :heavy_check_mark: | :heavy_check_mark: |
| (EXTRA) Serial.begin(driverName, speed) | :heavy_check_mark: | :heavy_check_mark: |
| (EXTRA) Serial.begin(driverName, speed, config)| :heavy_check_mark: | :heavy_check_mark: |
| Serial.end() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.find(target) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.findUntil(target, terminal) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.flush() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.parseFloat() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.parseInt() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.parseInt(char skipChar) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.peek() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.print(val)  | :heavy_check_mark: | :heavy_check_mark: |
| Serial.print(val, format)| :heavy_check_mark: | :heavy_check_mark: |
| Serial.println(val)  | :heavy_check_mark: | :heavy_check_mark: |
| Serial.println(val, format) | :heavy_check_mark: | :heavy_check_mark: |
| (EXTRA) Serial.printf(format, ...) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.read() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.readBytes(buffer, length)| :heavy_check_mark: | :heavy_check_mark: |
| Serial.readBytesUntil(character, buffer, length) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.readString() | :heavy_check_mark: | :heavy_check_mark: |
| Serial.readStringUntil(terminator) | :heavy_check_mark: | :heavy_check_mark: |
| (EXRTA) Serial.readStringCommand(character, buffer, length) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.setTimeout(time) | :heavy_check_mark: | :heavy_check_mark: |
| Serial.write(val)  | :heavy_check_mark: | :heavy_check_mark: |
| Serial.write(str)  | :heavy_check_mark: | :heavy_check_mark: |
| Serial.write(buf, len) | :heavy_check_mark: | :heavy_check_mark: |
| serialEvent() | In Progress | In Progress |

**Wire (I2C)**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| Wire.begin() | :heavy_check_mark: | :heavy_check_mark: |
| (EXTRA) Wire.begin(driverName) | :heavy_check_mark: | :heavy_check_mark: |
| Wire.begin(address) | :x: - Linux I2C Slave driver was added recently, still verifying | :x: |
| Wire.requestFrom(address, quantity) | :heavy_check_mark: | :heavy_check_mark: |
| Wire.requestFrom(address, quantity, stop) | :x: - There is no way to send an I2C stop msg to the driver | :x: |
| Wire.beginTransmission(address) | :heavy_check_mark: | :heavy_check_mark: |
| Wire.endTransmission() | :heavy_check_mark: | :heavy_check_mark: |
| Wire.endTransmission(stop)  | :x: - There is no way to send an I2C stop msg to the driver | :x: |
| Wire.write(value) | :heavy_check_mark: | :heavy_check_mark: |
| Wire.write(string)  | :heavy_check_mark: | :heavy_check_mark: |
| Wire.write(data, length) | :heavy_check_mark: | :heavy_check_mark: |
| Wire.available() | :heavy_check_mark: | :heavy_check_mark: |
| Wire.read()  | :heavy_check_mark: | :heavy_check_mark: |
| Wire.onReceive(handler) | :x: -- Linux I2C Slave driver was added recently, still verifying | :x: |
| Wire.onRequest(handler) | :x: -- Linux I2C Slave driver was added recently, still verifying | :x: |

**SPI**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| SPISettings | :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.begin() | :heavy_check_mark:  | :heavy_check_mark:  |
| (EXTRA) SPI.begin(driverName) | :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.end()| :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.beginTransaction(mySettings) | :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.endTransaction() | :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.setBitOrder(order) | :heavy_check_mark:  | :heavy_check_mark:  |
| SPI.setClockDivider(divider) | :heavy_check_mark: | :heavy_check_mark:  |
| SPI.setDataMode(mode) | :heavy_check_mark: | :heavy_check_mark:  |
| receivedVal = SPI.transfer(val) | :heavy_check_mark: | :heavy_check_mark:  |
| receivedVal16 = SPI.transfer16(val16) | :x: -- Not used | :x: |
| SPI.transfer(buffer, size) | :heavy_check_mark: | :heavy_check_mark:  |
| SPI.usingInterrupt(interruptNumber) | In Progress | In Progress |

---------------------------------------------------

**Time**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| time = millis()  | :heavy_check_mark: | :heavy_check_mark: |
| time = micros()  | :heavy_check_mark: | :heavy_check_mark: |
| delay(ms)  | :heavy_check_mark: | :heavy_check_mark: |
| delayMicroseconds(us)  | :heavy_check_mark: | :heavy_check_mark: |

**Math**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| min(x, y)  | :heavy_check_mark: | :heavy_check_mark: |
| max(x, y) | :heavy_check_mark: | :heavy_check_mark: |
| abs(x)  | :heavy_check_mark: | :heavy_check_mark: |
| constrain(x, a, b) | :heavy_check_mark: | :heavy_check_mark: |
| map(value, fromLow, fromHigh, toLow, toHigh)  | :heavy_check_mark: | :heavy_check_mark: |
| pow(base, exponent)  | :heavy_check_mark: | :heavy_check_mark: |
| radians(deg) | :heavy_check_mark: | :heavy_check_mark: |
| degrees(rad) | :heavy_check_mark: | :heavy_check_mark: |
| sqrt(x)  | :heavy_check_mark: | :heavy_check_mark: |
| sq(x)  | :heavy_check_mark: | :heavy_check_mark: |

**Trigonometry**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| sin(rad) | :heavy_check_mark: | :heavy_check_mark: |
| cos(rad) | :heavy_check_mark: | :heavy_check_mark: |
| tan(rad) | :heavy_check_mark: | :heavy_check_mark: |

**Characters**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| isAlphaNumeric(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isAlpha(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isAscii(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isWhitespace(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isControl(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isDigit(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isGraph(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isLowerCase(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isPrintable(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isPunct(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isSpace(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isUpperCase(thisChar) | :heavy_check_mark: | :heavy_check_mark: |
| isHexadecimalDigit(thisChar) | :heavy_check_mark: | :heavy_check_mark: |

**Random Numbers**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| randomSeed(seed)  | :heavy_check_mark: | :heavy_check_mark: |
| random(max)  | :heavy_check_mark: | :heavy_check_mark: |
| random(min, max)  | :heavy_check_mark: | :heavy_check_mark: |

**Bits and Bytes**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| lowByte(x) | :heavy_check_mark: | :heavy_check_mark: |
| highByte(x) | :heavy_check_mark: | :heavy_check_mark: |
| bitRead(x, n) | :heavy_check_mark: | :heavy_check_mark: |
| bitWrite(x, n, b) | :heavy_check_mark: | :heavy_check_mark: |
| bitSet(x, n) | :heavy_check_mark: | :heavy_check_mark: |
| bitClear(x, n) | :heavy_check_mark: | :heavy_check_mark: |
| bit(n) | :heavy_check_mark: | :heavy_check_mark: |

**External Interrupts**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| detachInterrupt(interrupt)  | :heavy_check_mark: | :x: --Waiting for pthreads |
| detachInterrupt(digitalPinToInterrupt(pin))  | :heavy_check_mark: | :x: --Waiting for pthreads |

**Interrupts**

| Function |  C++  | Javascript / wasm |
| ------ | ----------- | ----------- |
| interrupts()  | In Progress | In Progress |
| noInterrupts() | In Progress | In Progress |

----------------------------------------------------------

Check the [Arduino Language Reference](https://www.arduino.cc/reference/en/) for more info about each function.

# Support for Electron
TODO



