const linuxduino = require('linuxduino');

// Testing Serial readStringUntil
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var data = "";

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write Something (reads until letter x or timeout of 5 sec)...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  data = Serial.readStringUntil('x');
  console.log("Recieved data = ",data);

  Serial.end();
})();