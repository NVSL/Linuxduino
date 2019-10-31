const linuxduino = require('linuxduino');

// Testing Serial readStringCommand
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write something...");

  // Read string and wait for "enter"
  // Works as a termial (Ctrl^C to terminate)
  while(1) {
      var data = Buffer.alloc(50);
      data.fill(0);
      //  Read
      data = Serial.readStringCommand('\r', data, data.length);
      console.log("Recieved = ", data);
  }

  Serial.end();
})();