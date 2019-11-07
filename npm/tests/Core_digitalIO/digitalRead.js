const linuxduino = require('linuxduino');

// Test digitalRead
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var ledPin = 17; // Embedded board GPIO Number
  var input = 0;
  linuxduino.pinMode(ledPin, linuxduino.INPUT);
  while(1) {
    input = linuxduino.digitalRead(ledPin);
    console.log(input);
    linuxduino.delay(500);
  }
  return 0;
})();