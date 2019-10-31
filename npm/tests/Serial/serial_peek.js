const linuxduino = require('linuxduino');

// Testing Serial peek
// peek, -1 when nothing and afected by timeOut 
// Checks the next char of the serial without removing it.
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var peekChar;
      
  // Note: peek should not block.
  console.log("Write Something...");
  linuxduino.delay(5000);
  peekChar = Serial.peek();
  console.log("Your next char is = ", String.fromCharCode(peekChar));

  Serial.end();
})();