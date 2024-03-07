// library initialization
#include <SoftwareSerial.h> // calls a library called SoftwareSerial

// object initialization
SoftwareSerial espSerial(6, 7); // 6 As RX pin, 7 As TX pin -> Arduino Uno to ESP-01S

// variable initialization
const int sensorPin = A0; // define analog input using pin: A0
const String ssid = "YOUR_WIFI_NAME"; // define ssid name
const String password = "YOUR_WIFI_PASSWORD"; // define ssid password
const String server = "industrial.api.ubidots.com"; // define server
const int port = 80; // define ubidots port
const String device = "YOUR_UBIDOTS_DEVICE"; // define ubidots device
const String token = "YOUR_UBIDOTS_TOKEN"; // define ubidots token
const String topic1 = "YOUR_UBIDOTS_TOPIC1"; // define ubidots topic 1
const String topic2 = "YOUR_UBIDOTS_TOPIC2"; // define ubidots topic 2
int sensorValue; // this variable is used to store the soil moisture sensor value
String response; // this variable is used to receive response from ESP-01S
String Msg; // this variable is used to store all String data that will be sent
boolean StringReady = false; // this variable is initially set to false
unsigned long previousMillis = 0; // this variable will store last time sensor was updated
const long interval = 5000; // this variable as the interval to send data to ESP-01S (milliseconds)

// Method: setup
void setup(){  
  Serial.begin(9600); // start serial communication inside the Arduino Uno
  espSerial.begin(9600); // start serial communication to ESP-01S  
  while(!espSerial){ // if serial communication is not connected then do :
    ; // wait for serial port to connect
  }
}

// Method: loop
void loop(){
  sensorReadout(); // calling the sensorReadout method
  sendData(); // calling the sendData method
  wifiResponse(); // calling the wifiResponse method
}

// Method: sensorReadout
void sensorReadout(){
//  sensorValue = analogRead(sensorPin); // read the analog input
  sensorValue = random(1000); // read the dummy data
}

// Method: sendData
void sendData(){
  unsigned long currentMillis = millis(); // this variable is used to save the current time

  if (currentMillis - previousMillis >= interval) { // if the current time minus the previous time is greater than equal to the interval then :
    previousMillis = currentMillis; // previous time is the same as the current time
    Msg = ssid+','; // first data sent
    Msg += password+','; // second data sent
    Msg += server+','; // third data sent
    Msg += port+','; // fourth data sent
    Msg += device+','; // fifth data sent
    Msg += token+','; // sixth data sent
    Msg += topic1+','; // seventh data sent
    Msg += topic2+','; // eighth data sent
    Msg += sensorValue; // ninth data sent
    espSerial.print(Msg); // send data from Arduino Uno to ESP-01S with UART communication
  }
}

// Method: wifiResponse
void wifiResponse(){
  if(espSerial.available()){ // if serial communication is connected then do :
    response = ""; // this String data type is used to store data obtained from serial communication
    while(espSerial.available()){ // this loop is used to read the serial communication data from the ESP-01S
      response += espSerial.readString(); // adds each sensor data reading into a data string named response
      StringReady= true; // StringReady is true
    }
    if(StringReady){ // if the string is ready then :
      Serial.print(response); // print to serial monitor
    }
    delay(1000); // time delay in loop
  }
}
