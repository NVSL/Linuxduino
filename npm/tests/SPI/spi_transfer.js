const linuxduino = require('linuxduino');

// Testing spi transfer()
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
  
  // Open SPI port
  SPI = new linuxduino.SPI();
  SPI.begin("/dev/spidev0.0");

  // Set SPI Settings
  SPI.setClockDivider(linuxduino.SPI_CLOCK_DIV64);
  SPI.setBitOrder(linuxduino.MSBFIRST);
  SPI.setDataMode(linuxduino.SPI_MODE3);

  // Test transfer(buffer, len)
  var msg = "Hello World!\n";
  var rx = SPI.transfer(msg, msg.length);   // Send Hello World!\n
  process.stdout.write("Data Recieved = "); 
  for (var i=0; i<rx.length; i++){
      process.stdout.write(rx.charAt(i));
  }
  process.stdout.write("\n");

  // Test transfer(buffer, len)
  var msg2 = Buffer.from([0x41, 0x0A]);
  var rx = SPI.transfer(msg2, msg2.length);   // Send A\n
  process.stdout.write("Data Recieved = "); 
  for (var i=0; i<rx.length; i++){
      process.stdout.write(rx.charAt(i));
  }
  process.stdout.write("\n");


  // Test transfer(byte)
  var ret; 
  ret = SPI.transfer(0x42); // Send 'B'
  console.log("Data Recieved = "+String.fromCharCode(ret));
  ret = SPI.transfer(0x0A); // Send '\n'
  console.log("Data Recieved = "+String.fromCharCode(ret));

  SPI.end(); 
})();
