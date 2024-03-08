// library initialization
#include "Ubidots.h" // calls a library called Ubidots

// variable initialization
String data; // this variable is used to receive response from Arduino Uno
boolean StringReady = false; // this variable is initially set to false

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication
  while(!Serial){ // if serial communication is not connected then do :
    ; // wait for serial port to connect
  }
}

// Method: loop
void loop() { 
  retrievalAndTransmission(); // calling the retrievalAndTransmission method
}

// Method: retrievalAndTransmission
void retrievalAndTransmission(){
  data = ""; // this String data type is used to store data obtained from serial communication
  if(Serial.available()){ // if serial communication is connected then do :
    while(Serial.available()){ // this loop is used to read the serial communication data from the Arduino Uno
      data += Serial.readString(); // adds each sensor data reading into a data string named data
      StringReady= true; // StringReady is true
    }
    if (StringReady){ // if the string is ready then :
      data.trim(); // remove existing spaces
      String ssid = getValue(data, ',', 0); // this variable is used to store ssid data
      String password = getValue(data, ',', 1); // this variable is used to store password data
      String token = getValue(data, ',', 2); // this variable is used to store ubidots token data
      String variable = getValue(data, ',', 3); // this variable is used to store ubidots variable data
      String value = getValue(data, ',', 4); // this variable is used to store sensor data
      Ubidots ubidots(token.c_str(), UBI_HTTP);
      ubidots.wifiConnect(ssid.c_str(), password.c_str());
      ubidots.setDebug(true);  // uncomment this line to printing debug messages
      ubidots.add(variable.c_str(),value.toInt());  // send data: variable & value
      bool bufferSent = false; // bufferSent is false
      bufferSent = ubidots.send();  // will send data to a device label that matches the device Id
      if(bufferSent){ Serial.println("Values sent by the device"); } // do something if values were sent properly
    }
    delay(1000); // time delay in loop
  }
}

// function for data parsing
String getValue(String data, char separator, int index){ // there are 3 parameters: data -> string, separator -> character, index -> integer
  int found = 0; // variable with integer type to store found data
  int strIndex[] = {0, -1}; // variable with integer type to store two index values to be used as bounds when extracting substrings from the data string. the initial limit is 0, and the final limit is the final number read and then subtracted by 1
  int maxIndex = data.length()-1; // variable with integer type to store the upper limit of the index
 
  for(int i=0; i<=maxIndex && found<=index; i++){ // loop to search data
    if(data.charAt(i)==separator || i==maxIndex){ // if the character at index-i in the data string is equal to a separator character or index-i has reached the end of the string then
        found++; // increases the number of values that have been found during iteration through the string
        strIndex[0] = strIndex[1]+1; // to set the initial border of the substring that will be retrieved
        strIndex[1] = (i == maxIndex) ? i+1 : i; // to set the end limit of the substring to be retrieved
    }
  } 

  // returns a value based on the condition:
  // 1. checks whether the value found is greater than the index. if this condition is true, then the function will return the substring data starting from strIndex[0] to strIndex[1]
  // 2. if the condition is false (meaning the found value is not greater than the index), then the function will return an empty string meaning no value was found at the requested index
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
