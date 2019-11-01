const linuxduino = require('linuxduino');

// Testing TIME functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

    // Test millis
    var start_millis = linuxduino.millis();
    linuxduino.delay(1000); // Delay 1 sec
    var end_millis = linuxduino.millis();
    console.log("Delay 1000 millis = ", end_millis - start_millis);

    // Test micros
    var start_micros = linuxduino.micros();
    linuxduino.delayMicroseconds(1000000); // Delay 1 sec
    var end_micros = linuxduino.micros();
    console.log("Delay 1000000 micros = ", end_micros - start_micros);

})();