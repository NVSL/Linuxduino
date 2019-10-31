const linuxduino = require('linuxduino');

// Testing Serial writes
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var buff = "Hello World";

  if(Serial) { // This is just to test (if(Serial))
      Serial.write('A');
      Serial.write("Lol");
      Serial.write(buff, buff.length);
      Serial.write_byte(0x41); // Sends explicit byte
      Serial.write('\r');
      Serial.write('\n');
  }

  Serial.end();
})();