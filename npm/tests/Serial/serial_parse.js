const linuxduino = require('linuxduino');

// Testing Serial parseInt, prarseFloat
// Use another terminal for this.
// parseX waits until a character that is not a number is returned.  
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var Intvalue;
  var Floatvalue;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  console.log("Write Some Int...");
  linuxduino.delay(5000);
  Intvalue = Serial.parseInt();
  console.log("Your number Int Num is = ", Intvalue);
  console.log("Write Some Int (1 ignored)...");
  linuxduino.delay(5000);
  Intvalue = Serial.parseInt('1');
  console.log("Your number Int Num is = ", Intvalue);
  console.log("Write Some Double...");
  linuxduino.delay(5000);
  Floatvalue = Serial.parseFloat();
  console.log("Your number is = ", Floatvalue);

  Serial.end();
})();