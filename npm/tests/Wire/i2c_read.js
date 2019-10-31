const linuxduino = require('linuxduino');

// Testing I2C write
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin("/dev/i2c-1");

  Wire.requestFrom(8, 6);           // Request 6 bytes from slave device #8

  var available = Wire.available(); // Check available bytes sent from slave device
  console.log("Bytes available = ", available);
  if (available == 0 ) {            // Make sure we have communication with the device.
    console.log("Wrong I2C address or I2C wires may not be connected properly");
    return -1;
  }
  process.stdout.write("Message recieved = ");
  while (Wire.available()) {        
    var c = Wire.read();            // Read bytes as character
    process.stdout.write(String.fromCharCode(c));
  }
  console.log("");

  Wire.end();
  return 1;
})();