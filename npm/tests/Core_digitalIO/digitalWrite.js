const linuxduino = require('linuxduino');

// Test digitalWrite
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var ledPin = 4; // Embedded board GPIO Number
  linuxduino.pinMode(ledPin, linuxduino.OUTPUT);
  while(1) {
    console.log("LED ON");
    linuxduino.digitalWrite(ledPin, linuxduino.HIGH);
    linuxduino.delay(1000); // Delay 1 sec
    console.log("LED OFF");
    linuxduino.digitalWrite(ledPin, linuxduino.LOW);
    linuxduino.delay(1000); // Delay 1 sec
  }
  return 0;
})();