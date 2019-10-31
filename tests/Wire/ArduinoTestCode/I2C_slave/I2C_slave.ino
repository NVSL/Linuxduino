#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Serial.begin(115200);           // start serial for output
  Wire.onReceive(receiveEvent);   // register event
  Wire.onRequest(requestEvent);   // register event
  Serial.println("I2C setup done");  // start serial for output
}

void loop() {
  delay(100);
}

// ** Only for sending
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void requestEvent() {
   Wire.write("hello "); // respond with message of 6 bytes
   Serial.println("Message sent");
}

// ** Only for receiving
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  Serial.println("Message received");
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  Serial.println("");
}
