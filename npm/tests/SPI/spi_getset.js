const linuxduino = require('linuxduino');

// Testing SPI set/get
(async() => {
  // Wait for wasm file
  await linuxduino.ready;
    
    // Set SPI device name
    linuxduino.setSPI("/dev/spidev0.0");
    console.log(linuxduino.getSPI());

    // Open SPI port
    SPI = new linuxduino.SPI();
    SPI.begin();

    // Set SPI Settings
    settingsA = new linuxduino.SPISettings(linuxduino.SPI_CLOCK_DIV64, 
        linuxduino.MSBFIRST, linuxduino.SPI_MODE3);
    
    // Send Hello World!
    SPI.beginTransaction(settingsA);
    // Note in SPI the last character will not be printed here. 
    // In SPI you recieve what you sent previously.
    var msg = Buffer.from("Hello World!\n")
    for (var i = 0; i < msg.length ; i++) {
        ret = SPI.transfer(msg[i]);
        process.stdout.write(String.fromCharCode(ret));
    }
    SPI.endTransaction();
    process.stdout.write('\n');
    
    SPI.end();
})();