const linuxduino = require('linuxduino');

// Testing set/get I2C device name
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  linuxduino.setWire("/dev/i2c-1");
  console.log("Current I2C Driver = ", linuxduino.getWire());

  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin(); 

  Wire.beginTransmission(8); // 7-bit device I2C address
  Wire.write("Hello World");
  var bytes_transmitted = Wire.endTransmission();
  // Make sure transmission was sucessful
  if (bytes_transmitted == 0 ) {
    console.log("Wrong I2C address or I2C wires may not be connected properly");
    return -1;
  }
  console.log("Hello World msg sent!");

  Wire.end(); 
  return 1;
})();