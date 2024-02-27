// library initialization
#include <SoftwareSerial.h> // calls a library called SoftwareSerial

// object initialization
SoftwareSerial espSerial(2, 3); // 2 As RX pin, 3 As TX pin -> Arduino Uno to ESP-01

// variable initialization
#define sensorPin A0 // defines analog input using pin: A0

// Method: setup
void setup(){  
  Serial.begin(9600); // start serial communication inside the Arduino Uno
  espSerial.begin(115200); // start serial communication to ESP-01
}

// Method: loop
void loop(){
  int moisture = analogRead(sensorPin); // read the analog input
  espSerial.println(moisture); // send data from Arduino Uno to ESP-01 with UART communication
  delay(5000); // time delay in loop
}
