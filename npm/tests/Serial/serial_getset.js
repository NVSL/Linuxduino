const linuxduino = require('linuxduino');

(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
	linuxduino.setSerial("/dev/ttyUSB0");
	Serial.begin(115200);

	console.log("Current Serial Driver = ", linuxduino.getSerial());
	console.log("Sending Hello World...");
	Serial.println("Hello World");
	Serial.end();

	return 0;
})();