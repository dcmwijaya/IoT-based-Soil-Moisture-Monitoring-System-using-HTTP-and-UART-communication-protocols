// library initialization
#include <SoftwareSerial.h> // calls a library called SoftwareSerial

// object initialization
SoftwareSerial espSerial(2, 3); // 2 As RX pin, 3 As TX pin -> Arduino Uno to ESP-01

// variable initialization
String ssid = "YOUR_WIFI_NAME"; // ssid name
String password = "YOUR_WIFI_PASSWORD"; // ssid password
String data; // data with String type
boolean StringReady = false;

// Method: setup
void setup(){  
  Serial.begin(9600); // start serial communication inside the Arduino Uno
  espSerial.begin(9600); // start serial communication to ESP-01  
  wifiResponse(); // calling the wifiResponse method
}

// Method: loop
void loop(){
  espSerial.print(ssid+","+password); // send data from Arduino Uno to ESP-01 with UART communication
  delay(5000); // time delay in loop   
  wifiResponse(); // calling the wifiResponse method
}

// Method: dataRetrieval
void wifiResponse(){
  if(espSerial.available()){ // if serial communication is connected then do :
    data = ""; // this String data type is used to store data obtained from serial communication
    while(espSerial.available()){ // this loop is used to read the serial communication data from the Arduino Uno
      data += espSerial.readString(); // adds each sensor data reading into a data string named data
      StringReady= true;
    }
    if (StringReady){
      data.trim(); // remove existing spaces
      Serial.println("Response: " + data);
    }
    delay(1000); // time delay in loop
  }
}
