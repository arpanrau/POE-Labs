#include <Adafruit_MotorShield.h>

/*
  IRSensorTest 
  Reads an analog input on pin 0 and pin 1, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach circuit to 5v and ground and outputs to pin A0 and pin A1
*/

String index = ";"; //index for output string

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int SensorValue1 = analogRead(A0);
  int SensorValue2 = analogRead(A1); 
  // print out the value you read:
  Serial.println(String(SensorValue1) + index + String(SensorValue2));
  delay(1);        // delay in between reads for stability
}
