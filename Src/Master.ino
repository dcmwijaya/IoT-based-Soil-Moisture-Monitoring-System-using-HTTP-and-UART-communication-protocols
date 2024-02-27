// library initialization
#include <ESP8266WiFi.h> // calls a library called ESP8266WiFi
#include <PubSubClient.h> // calls a library called PubSubClient
#include <ArduinoJson.h> // calls a library called ArduinoJson

// object initialization
WiFiClient espClient; // create a new object with the name: espClient
PubSubClient client(espClient); // create a new object with the name: client
StaticJsonDocument<256> DataPublish; // create a new object with the name: DataPublish

// variable initialization
#define ssid "YOUR_WIFI_NAME" // router name
#define password "YOUR_WIFI_PASSWORD" // router password
#define mqtt_server "IOT_PLATFORM" // mqtt server
#define mqtt_topic "Moisture Sensor" // mqtt topic
String clientId = "YOUR_CLIENT_ID"; // client id from IoT Platform
char Payload[128]; // data with character type is used for payload purposes
#define wetSoil 277 // maximum value considered as 'wet' soil
#define drySoil 380 // minimum value considered as 'dry' soil
int moisture; // data with integer type is used for moisture sensor purposes
String status; // data with String type is used for moisture sensor purposes

// Method: setup
void setup(){
  Serial.begin(115200); // start serial communication inside the ESP-01
  WiFiconnection(); // calling the WiFiconnection method
  client.setServer(mqtt_server, 1883); // set server & port
  while(!Serial){ // if serial communication is not connected then do :
    ; // wait for serial port to connect
  }
}

// Method: loop
void loop(){
  dataRetrieval(); // calling the dataRetrieval method
  soilCondition(); // calling the soilCondition method
  if (!client.connected()) { reconnect(); } // if the client is not connected then run the method called reconnect
  client.loop(); // if the client is not connected then client requests will be conducted continuously
  dataPublish(); // calling the dataPublish method
}

// Method: WiFiconnection
void WiFiconnection(){
  delay(500); // time delay in loop
  Serial.print("Connecting to WiFi: "); Serial.println(ssid); // print to serial monitor
  WiFi.begin(ssid, password); // starting wifi
  while(WiFi.status() != WL_CONNECTED){ // while not successfully connect to the WiFi then :
    delay(500); // time delay in loop
    Serial.print("."); // print to serial monitor continuously
  }     
  if(WiFi.status() == WL_CONNECTED){ // if successfully connect to the WiFi then :
    Serial.println(""); Serial.println("Connected to WiFi !!"); Serial.print("IP address : "); Serial.println(WiFi.localIP()); Serial.println("\n"); // print to serial monitor
  }
  else{ // if not successfully connect to the WiFi then : 
    Serial.println("\nFailed to connect to WiFi !!"); // print to serial monitor
  } 
}

// Method: reconnect
void reconnect() {
  while(!client.connected()) { // while client not successfully connect to the server then :
    Serial.print("Attempting MQTT connection..."); // print to serial monitor
    clientId += String(random(0xffff), HEX); // Create a random client ID to make it different from other people's client ID
    if(client.connect(clientId.c_str())){ // if client successfully connect to the server then :
      Serial.println("Connected"); // print to serial monitor
    } else { // if client not successfully connect to the server then :
      Serial.print("failed, rc="); Serial.print(client.state()); Serial.println("try again in 5 seconds"); // print to serial monitor
      delay(5000); // time delay in loop
    }
  }
}

// Method: dataRetrieval
void dataRetrieval(){
  if(Serial.available()){ // if serial communication is connected then do :
    while(Serial.available()){ // this loop is used to read the serial communication data from the Arduino Uno
      moisture += char(Serial.read()); // adds each sensor data reading into a data string named moisture
    }
    delay(5000); // time delay in loop
    Serial.println("\nAnalog value: "); Serial.println(moisture); // print to serial monitor
  }
}

// Method: soilCondition
void soilCondition(){
  // determine status of soil
  if (moisture < wetSoil) { // if the sensor value is less than 277 then :
    status = "wet"; // wet soil conditions
    Serial.println("Status: "+String(status)); // print to serial monitor
  } else if (moisture >= wetSoil && moisture < drySoil) { // if the sensor value is within the range of 277 - 380 then :
    status = "moist"; // moist soil conditions
    Serial.println("Status: "+String(status)); // print to serial monitor
  } else { // if the sensor value is not in wet and moist conditions then :
    status = "dry"; // dry soil conditions
    Serial.println("Status: "+String(status)); // print to serial monitor
  }
}

// Method: dataPublish
void dataPublish(){
  DataPublish["value"] = String(moisture); // this data array is used to store the value of the soil moisture sensor measurement results
  DataPublish["status"] = String(status); // this data array is used to store the status of the soil moisture sensor measurement results
  serializeJson(DataPublish, Payload); // produces JSON data output without indentation
  boolean dataout = client.publish(mqtt_topic, Payload); // data published
  Serial.println("\n----------------------------------------------"); Serial.println("Json Packages: " + String(Payload)); Serial.println("Publish Information: Data Sent"); Serial.println("----------------------------------------------"); // print to serial monitor
  delay(2000); // time delay in loop
}
