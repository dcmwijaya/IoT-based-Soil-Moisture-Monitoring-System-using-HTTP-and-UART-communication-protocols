// variable initialization
#define wetSoil 277 // define max value we consider soil 'wet'
#define drySoil 380 // define min value we consider soil 'dry'
#define sensorPin A0 // define analog input

// Method: setup
void setup(){  
  Serial.begin(9600); // baudrate: 9600
}

// Method: loop
void loop(){
  int moisture = analogRead(sensorPin); // read the analog input
  Serial.print("Analog output: "); Serial.println(moisture); // print to serial monitor
  
  // determine status of soil
  if (moisture < wetSoil) { // if the sensor value is less than 277 then:
    Serial.println("Status: wet soil conditions\n"); // print to serial monitor
  } else if (moisture >= wetSoil && moisture < drySoil) { // if the sensor value is within the range of 277 - 380 then:
    Serial.println("Status: moist soil conditions\n"); // print to serial monitor
  } else { // if the sensor value is not in wet and moist conditions then:
    Serial.println("Status: dry soil conditions\n"); // print to serial monitor
  }
  
  delay(1000); // time delay in loop
}
