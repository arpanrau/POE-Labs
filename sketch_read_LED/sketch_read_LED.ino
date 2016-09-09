
int analogPin = 0;  //Infrared Sensor connected to analog pin 0

int val_read = 0; // variable to store the value read

void setup()

{
  Serial.begin(9600); //setup serial
}

void loop()
   
{
   val_read = analogRead(analogPin); //read input pin
   
   Serial.println(val_read); //debug value
   
}


