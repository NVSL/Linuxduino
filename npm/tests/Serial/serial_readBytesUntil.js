const linuxduino = require('linuxduino');

// Testing Serial readBytesUntil, setTimeout
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var buff = Buffer.alloc(100);

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);
    
  console.log("Write Something (reads until letter x or timeout of 5 sec)...");

  Serial.setTimeout(5000);  // Set timeout of 5 seconds

  // Clean buffer
  buff.fill(0);

  // Read bytes until x is found or timeout
  buff = Serial.readBytesUntil('x', buff, 100);
  console.log("Recieved = ", buff);

  Serial.end();
})();