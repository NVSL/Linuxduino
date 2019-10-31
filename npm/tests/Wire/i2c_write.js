const linuxduino = require('linuxduino');

// Testing I2C write
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var world = new Buffer("World");
  
  // Open I2C port
  Wire = new linuxduino.Wire();
  Wire.begin("/dev/i2c-1");
  
  // Send Hello World! to device
  Wire.beginTransmission(8); // 7-bit device I2C address
  Wire.write("Hello");
  Wire.write(" ");
  Wire.write(world, world.length);
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