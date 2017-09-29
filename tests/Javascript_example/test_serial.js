var Linuxduino = require("./serial.js");

Linuxduino.onRuntimeInitialized = function() {
    console.log('Initialize');
    // ### CORE
    //Linuxduino.Serial.begin("/drivers/ttyUSB0", 115200, 0x06);
    // var ledPin = 4; // GPIO4
    // Linuxduino.pinMode(ledPin, 0x01);
    // while (1) {
    // 	console.log("LED ON");
    // 	Linuxduino.digitalWrite(ledPin, 1);
    // 	Linuxduino.delay(1000);
    // 	console.log("LED OFF");
    // 	Linuxduino.digitalWrite(ledPin, 0);
    // 	Linuxduino.delay(1000);
    // }
    // ### SERIAL
    Linuxduino.setSerial("/devices/ttyUSB0");
    console.log(Linuxduino.getSerial());
    Serial =  new Linuxduino.Serial();
    //Serial.begin(115200, 0x06);
    //Serial.begin("/devices/ttyUSB0", 115200);
    Serial.begin(115200);
    var buf = new Buffer("Hi World");
    Serial.println(buf);
    Serial.println("Hello World");
    // Serial.println(42, Linuxduino.HEX);
    // var buffer = new Buffer(5);
    // buffer[0] = 64;
    // buffer[1] = 65;
    // buffer[2] = 66;
    // buffer[3] = 67;
    // buffer[4] = 68;
    // Serial.write(buffer, buffer.length);
    // Selial.println("");
    // console.log("Write Something");
    // Serial.setTimeout(5000);  // Set timeout of 5 seconds
    // var data = Serial.readString();
    // console.log("Recieved data = "+ data);
    Serial.end();
    // ### SPI
    // settingsA = new Linuxduino.SPISettings(Linuxduino.SPI_CLOCK_DIV64, Linuxduino.MSBFIRST, Linuxduino.SPI_MODE3);
    // SPI =  new Linuxduino.SPI();
    // SPI.begin("/devices/spidev0.0");
    // buff = new Buffer("Hello World\n");
    // var ret;
    // while(1) {
    // 	SPI.beginTransaction(settingsA);
    // 	for(var i=0; i<buff.length; i++){
    // 		ret = SPI.transfer(buff[i]);
    // 		process.stdout.write(String.fromCharCode(ret));
    // 	}
    // 	process.stdout.write('\n');
    // 	SPI.endTransaction();
    // 	Linuxduino.delay(1000);
    // }
    // SPI.end();
    // ### Wire
    // var world = new Buffer("World!");
    // Wire =  new Linuxduino.Wire();
    // Wire.begin("/devices/i2c-1");
    // Wire.beginTransmission(8);
    // Wire.write("Hello");
    // Wire.write("|");
    // Wire.write(world, world.length);
    // Wire.endTransmission();
    // Wire.end();
}