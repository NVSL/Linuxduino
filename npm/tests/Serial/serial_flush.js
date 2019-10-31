const linuxduino = require('linuxduino');

(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write something on the other terminal (5 sec wait)...");
  linuxduino.delay(5000);

  // Memory allocation in js necessary
  let mem = new Buffer.alloc(10);

  //  Read 2 bytes
  var buff1 = Serial.readBytes(mem, 2);
  console.log("Recieved 1 = ", buff1);

  // Clear Serial buffer
  Serial.flush();

  //  Read 2 bytes (Should print nothing - flush)
  var buff2 = Serial.readBytes(mem, 2);
  console.log("Recieved 2 = ", buff2);

  Serial.end();
})();