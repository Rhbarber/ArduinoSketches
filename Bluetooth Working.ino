#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2);

void setup() {
  Serial.begin(9600); //open the serial port
  mySerial.begin(9600); // open the bluetooth serial port
}

void loop() {
  if(mySerial.available()){
    Serial.println(mySerial.readString()); // send from serial to bluetooth
  }
  if(Serial.available()){
    mySerial.println(Serial.readString()); // send from bluetooth to serial
  }
}
