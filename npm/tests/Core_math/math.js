const linuxduino = require('linuxduino');

// Testing MATH functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  console.log("abs (-11) = ", linuxduino.abs(-11));
  console.log("constrain (3, 10, 150) = ", linuxduino.constrain(3,10,150));
  console.log("constrain (151, 10, 150) = ", linuxduino.constrain(151,10,150));
  console.log("constrain (50, 10, 150) = ", linuxduino.constrain(50,10,150));
  console.log("map (5, 0, 10, -10, -20) = ", linuxduino.map (5, 0, 10, -10, -20));
  console.log("max (4,6) = ", linuxduino.max(4,6));
  console.log("min (4,6) = ", linuxduino.min(4,6));
  console.log("pow(2,3) = ", linuxduino.pow(2,3));
  console.log("sqrt(4) = ", linuxduino.sqrt(4));
  console.log("sq(2) = ", linuxduino.sq(2));
  console.log("round(4.678) = ", linuxduino.round(4.678));
  console.log("radians(180) = ", linuxduino.radians(180));
  console.log("degrees(3.141593) = ", linuxduino.degrees(3.141593));

})();