// library initialization
#include <SoftwareSerial.h> // calls a library called SoftwareSerial

// object initialization
SoftwareSerial espSerial(6, 7); // 6 As RX pin, 7 As TX pin -> Arduino Uno to ESP-01S

// variable initialization
const int sensorPin = A0; // define analog input using pin: A0
const String ssid = "YOUR_WIFI_NAME"; // define ssid name
const String password = "YOUR_WIFI_PASSWORD"; // define ssid password
const String device = "YOUR_UBIDOTS_DEVICE"; // define ubidots device
const String topic = "YOUR_UBIDOTS_TOPIC"; // define ubidots topic
const String id = "YOUR_UBIDOTS_ID"; // define ubidots id
const String token = "YOUR_UBIDOTS_TOKEN"; // define ubidots token
int sensorValue; // data with integer type to store the soil moisture sensor value
String response; // data with string type to receive response from ESP-01S
boolean StringReady = false; // data with boolean type is initially set to false

// Method: setup
void setup(){  
  Serial.begin(9600); // start serial communication inside the Arduino Uno
  espSerial.begin(9600); // start serial communication to ESP-01S  
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
  espSerial.print(ssid+","+password+","+device+","+topic+","+id+","+token+","+sensorValue); // send data from Arduino Uno to ESP-01S with UART communication
  delay(5000); // time delay in loop
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
      response.trim(); // remove existing spaces
      Serial.println("WiFi status: " + response); // print to serial monitor
      if(response == "Connected"){ // if the response is equal to "Connected" then :
        Serial.println("Send sensor data: "+String(sensorValue)+"\n"); // print to serial monitor
      }
    }
    delay(1000); // time delay in loop
  }
}
