const linuxduino = require('linuxduino');

// Test BITS AND BYTES functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  var value;

  // bit(1)
  console.log("0x02 & bit(1) = ", (0x02 & linuxduino.bit(1)));
  // bitClear()
  value = 0x02;
  linuxduino.bitClear(value, 1);
  console.log("bitClear(0x02, 1) = ", value);
  // bitRead() 
  console.log("bitRead(0x02, 1) = ", linuxduino.bitRead(0x02, 1));
  // bitSet()
  value = 0x00;
  linuxduino.bitSet(value, 1);
  console.log("bitSet(0x00, 1) = ", value);
  // bitWrite()
  value = 0x00; 
  linuxduino.bitWrite(value, 0, 1);
  console.log("bitWrite(0x00, 0, 1) = ", value);
  // highByte()
  console.log("highByte(0xABCD) = ", linuxduino.highByte(0xABCD).toString(16).toUpperCase());
  // lowByte()
  console.log("lowByte(0xABCD) = ", linuxduino.lowByte(0xABCD).toString(16).toUpperCase());

})();