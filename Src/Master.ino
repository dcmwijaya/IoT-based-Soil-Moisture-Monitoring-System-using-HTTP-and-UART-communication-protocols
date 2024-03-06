// library initialization
#include <ESP8266WiFi.h> // calls a library called ESP8266WiFi

// variable initialization
String data;
boolean StringReady = false;

void setup() {
  Serial.begin(9600); // start serial communication inside the ESP-01
  while(!Serial){ // if serial communication is not connected then do :
    ; // wait for serial port to connect
  }
}

void loop() { 
  dataRetrieval(); // calling the dataRetrieval method
}

// Method: WiFiconnection
void WiFiconnection(String ssid, String password){
  WiFi.begin(ssid, password); // starting wifi   
  if(WiFi.status() == WL_CONNECTED){ // if successfully connect to the WiFi then :
    Serial.println("\nWiFi Connected !!"); // send response to Arduino Uno
  }
  if(WiFi.status() != WL_CONNECTED){ // if not successfully connect to the WiFi then : 
    while(WiFi.status() != WL_CONNECTED){ // while not successfully connect to the WiFi then :
      delay(500); // time delay in loop
      Serial.print("."); // send response to Arduino Uno
    }  
  } 
}

// Method: dataRetrieval
void dataRetrieval(){
  data = ""; // this String data type is used to store data obtained from serial communication
  if(Serial.available()){ // if serial communication is connected then do :
    while(Serial.available()){ // this loop is used to read the serial communication data from the Arduino Uno
      data += Serial.readString(); // adds each sensor data reading into a data string named data
      StringReady= true;
    }
    if (StringReady){
      data.trim(); // remove existing spaces
      String ssid = getValue(data, ',', 0); // this variable is used to store ssid data
      String password = getValue(data, ',', 1); // this variable is used to store password data
      WiFiconnection(ssid, password);
    }
    delay(1000);
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
