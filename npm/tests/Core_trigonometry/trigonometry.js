const linuxduino = require('linuxduino');

// Testing TRIGONOMETRY functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  console.log("cos(3.1416) = ", linuxduino.cos(3.1416)); // -1...
  console.log("sin(3.1416) = ", linuxduino.sin(3.1416)); // -0...
  console.log("tan(3.1416) = ", linuxduino.tan(3.1416)); //  0...

})();