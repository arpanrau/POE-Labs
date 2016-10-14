

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorPin2 = A1;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor

void setup() {
  begin Serial(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  sensorValue2 = analogRead(sensorPin2);  
  
  Serial.println(sensorValue);
  Serial.println(sensorValue2);

  delay(250);  
}
