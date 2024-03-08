// library initialization
#include <ESP8266WiFi.h> // calls a library called ESP8266WiFi

// object initialization
WiFiClient client; // names the object of WiFiClient with the name -> client

// variable initialization
#define wetSoil 277 // define the maximum value that is considered as 'wet' soil
#define drySoil 380 // define the minimum value that is considered as 'dry' soil
String data; // this variable is used to receive response from Arduino Uno
boolean StringReady = false; // this variable is initially set to false
int status; // this variable is used to accommodate soil status (1:wet, 2:moist, 3:dry)
unsigned long previousMillis = 0; // this variable will store last time sensor was updated
const long interval = 1000; // this variable as the interval to send data to IoT Platform (milliseconds)

// Method: setup
void setup() {
  Serial.begin(9600); // start serial communication
  while(!Serial){ // if serial communication is not connected then do :
    ; // wait for serial port to connect
  }
}

// Method: loop
void loop() { 
  RetrievalTransmission(); // calling the RetrievalTransmission method
}

// Method: WiFiconnection
void WiFiconnection(String ssid, String password){
  WiFi.begin(ssid, password); // starting wifi   
  Serial.println("\nWiFi status: connecting to "+ssid); // send response to Arduino Uno
  if(WiFi.status() == WL_CONNECTED){ // if successfully connect to the WiFi then :
    Serial.println("WiFi status: connected"); // send response to Arduino Uno
  }
  if(WiFi.status() != WL_CONNECTED){ // if not successfully connect to the WiFi then :
    Serial.println("WiFi status: not connected"); // send response to Arduino Uno
  }
  WiFi.setAutoReconnect(true);
}

// Method: RetrievalTransmission
void RetrievalTransmission(){
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
      String host = getValue(data, ',', 2); // this variable is used to store ubidots host data
      String port = getValue(data, ',', 3); // this variable is used to store ubidots port data
      String token = getValue(data, ',', 4); // this variable is used to store ubidots token data
      String variable = getValue(data, ',', 5); // this variable is used to store ubidots variable data
      String variableID = getValue(data, ',', 6); // this variable is used to store ubidots variableID data
      String sensorValue = getValue(data, ',', 7); // this variable is used to store sensor data
      manageData(ssid, password, host, port.toInt(), token, variable, variableID, sensorValue.toInt()); // input ssid, password, server, port, device, token, topic1, topic2, sensorValue data into the sendData method
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

// Method: soilCondition
void soilCondition(int sensorValue){
  // determine status of soil
  if (sensorValue < wetSoil) { // if the sensor value is less than 277 then :
    status = 1; // wet soil conditions
  } else if (sensorValue >= wetSoil && sensorValue < drySoil) { // if the sensor value is within the range of 277 - 380 then :
    status = 2; // moist soil conditions
  } else { // if the sensor value is not in wet and moist conditions then :
    status = 3; // dry soil conditions
  }
}

// Method: manageData
void manageData(String ssid, String password, String host, int port, String token, String variable, String variableID, int sensorValue){
  unsigned long currentMillis = millis(); // to save the current time

  if (currentMillis - previousMillis >= interval) { // if the current time minus the previous time is greater than equal to the interval then :
    previousMillis = currentMillis; // previous time is the same as the current time
    
    WiFiconnection(ssid, password); // input ssid and password data into the WiFiconnection method
    soilCondition(sensorValue); // input sensorValue data into the soilCondition method
    
    Serial.println("\nServer status: connecting to "+host); // send response to Arduino Uno
    
    if(!client.connect(host, port)){ // if client is not connected then do :
      Serial.println("Server status: not connected");  // send response to Arduino Uno 
    }
    
    if(client.connect(host, port)){ // if client is connected then do :
      Serial.println("Server status: connected\n"); // send response to Arduino Uno 

      // http request on rest API
      client.print("POST /api/v1.6/variables/"+variableID+" HTTP/1.1\r\n");
      client.print("Host: "+host+"\r\n");
      client.print("X-Auth-Token: ");
      client.print(token);
      client.print("\r\n");
      client.print("Content-Type: application/json\r\n");
      String buff = "";
      buff += "{";
      buff += "\""+variable+"\":"+sensorValue;
      buff += "}\r\n";
      int dataLength = buff.length()-1;
      String dataLengthStr = String(dataLength);
      client.print("Content-Length: ");
      client.println(dataLengthStr);
      client.println();
      client.println(buff); 
    }

    while(client.available()){ // while client is connected then do :
      char c = client.read(); // this variable is used to read the data sent to the IoT Platform
      Serial.print(c); // send response to Arduino Uno
    }
    
    if(client.connected()){ // if client is connected then do :
      Serial.println("Disconnecting from Ubidots..."); // send response to Arduino Uno
      client.stop(); // done with this iteration, close the connection
    }
  }
}
