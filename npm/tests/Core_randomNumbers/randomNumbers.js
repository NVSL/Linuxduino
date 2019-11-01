const linuxduino = require('linuxduino');

// Test RANDOM NUMBERS functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  linuxduino.randomSeed(10);
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random(10) = ", linuxduino.random(10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
  console.log("random (5, 10) = ", linuxduino.random(5, 10));
    
})();