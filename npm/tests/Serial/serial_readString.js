const linuxduino = require('linuxduino');

// Testing Serial readString
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var data = "";

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write Something...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  // Read data as string until timeout 
  data = Serial.readString();
  console.log("Recieved data = ", data);

  Serial.end();
})();