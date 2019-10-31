const linuxduino = require('linuxduino');

// Testing Serial readBytes
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var buff = Buffer.alloc(10);

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);
    
  console.log("Write Something (Recieves max 5 bytes)...");
  linuxduino.delay(5000);

  // Clean buffer
  buff.fill(0);

  //  Read 5 bytes
  buff = Serial.readBytes(buff, 5);
  console.log("Recieved = ", buff);

  Serial.end();
})();