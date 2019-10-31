const linuxduino = require('linuxduino');

// Testing Serial print, println, printf
(async() => {
  // Wait for wasm file
  await linuxduino.ready;

  // Open Serial port
  Serial = new linuxduino.Serial();
  Serial.begin("/dev/ttyUSB0", 115200);

	var message = "A char message";
  
  // Printf 
  // (Not possible in JS since embind doesn't support multiple args loader)

  // Print
  Serial.print("A const char message ");
  Serial.print("(no new line)");
  Serial.println("A const char message ");
  Serial.println("(new line)");
  Serial.print(message);
  Serial.println(message);

  // Println
  Serial.println(15, linuxduino.DEC);
  Serial.println(15, linuxduino.OCT);
  Serial.println(15, linuxduino.HEX);
  Serial.println(15, linuxduino.BIN);
  Serial.println(-15, linuxduino.DEC);
  Serial.println(-15, linuxduino.OCT);
  Serial.println(-15, linuxduino.HEX);
  Serial.println(-15, linuxduino.BIN);

  // **Added for javascript (Sends explicit byte)
  Serial.print_byte(0x41);    // Sends ascii A
  Serial.println_byte(0x42);  // Sends ascii B


  Serial.end();
})();