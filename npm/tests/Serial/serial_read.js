const linuxduino = require('linuxduino');

// Testing Serial read and available
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

  var incomingByte;
  var availableBytes;
    
  console.log("Write Something...");
  linuxduino.delay(5000);

  // Check if there is available data:
  if ((availableBytes = Serial.available()) > 0) {

    console.log("Available bytes = ", availableBytes);

    for (var i=0; i<availableBytes; i++) {
        // read incoming byte:
        incomingByte = Serial.read();
        // print incoming byte:
        console.log(`Incoming Byte ${i}: ${String.fromCharCode(incomingByte)}`);
    }

  } else {
      console.log("Nothing available");
  }

  Serial.end();
})();