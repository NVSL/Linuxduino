const linuxduino = require('linuxduino');

// Testing CHARACTERS functions
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  console.log("isAlpha('a') = ", linuxduino.isAlpha( Buffer.from('a')[0] ));
  console.log("isAlpha('1') = ", linuxduino.isAlpha( Buffer.from('1')[0] ));
  console.log("isAlphaNumeric('a') = ", linuxduino.isAlphaNumeric( Buffer.from('a')[0] ));
  console.log("isAlphaNumeric('\\n') = ", linuxduino.isAlphaNumeric( Buffer.from('\n')[0] ));
  console.log("isAscii(0x41) = ", linuxduino.isAscii(0x41));
  console.log("isAscii(1234) = ", linuxduino.isAscii(1234));
  console.log("isControl('\\r') = ", linuxduino.isControl( Buffer.from('\r')[0] ));
  console.log("isControl('a') = ", linuxduino.isControl( Buffer.from('a')[0] ));
  console.log("isDigit('0') = ", linuxduino.isDigit( Buffer.from('0')[0] ));
  console.log("isDigit('a') = ", linuxduino.isDigit( Buffer.from('a')[0] ));
  console.log("isGraph('a') = ", linuxduino.isGraph( Buffer.from('a')[0] ));
  console.log("isGraph(' ') = ", linuxduino.isGraph( Buffer.from(' ')[0] ));
  console.log("isHexadecimalDigit('F') = ", linuxduino.isHexadecimalDigit( Buffer.from('F')[0] ));
  console.log("isHexadecimalDigit('G') = ", linuxduino.isHexadecimalDigit( Buffer.from('G')[0] ));
  console.log("isLowerCase('a') = ", linuxduino.isLowerCase( Buffer.from('a')[0] ));
  console.log("isLowerCase('A') = ", linuxduino.isLowerCase( Buffer.from('A')[0] ));
  console.log("isPrintable('a') = ", linuxduino.isPrintable( Buffer.from('a')[0] ));
  console.log("isPrintable('\\r') = ", linuxduino.isPrintable( Buffer.from('\r')[0] ));
  console.log("isPunct(',') = ", linuxduino.isPunct( Buffer.from(',')[0] ));
  console.log("isPunct('a') = ", linuxduino.isPunct( Buffer.from('a')[0] ));
  console.log("isSpace('\\t') = ", linuxduino.isSpace( Buffer.from('t')[0] ));
  console.log("isSpace('a') = ", linuxduino.isSpace( Buffer.from('a')[0] ));
  console.log("isUpperCase('A') = ", linuxduino.isUpperCase( Buffer.from('A')[0] ));
  console.log("isUpperCase('a') = ", linuxduino.isUpperCase( Buffer.from('a')[0] ));
  console.log("isWhitespace(' ') = ", linuxduino.isWhitespace( Buffer.from(' ')[0] ));
  console.log("isWhitespace('a') = ", linuxduino.isWhitespace( Buffer.from('a')[0] ));

})();