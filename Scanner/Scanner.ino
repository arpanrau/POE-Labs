
#include <Servo.h>  //include servo library
 
Servo panservo; // create servo objects 
Servo tiltservo; 
               
 
int panpos = 0;    // variable to store the servo pan position 
int tiltpos = 0;   // variable to store the servo tilt position 
int range = 0;     // variable to store the servo range
String index = ";"; //index for output string
 
 
void setup() 
{ 
  Serial.begin(9600);  //begin serial at 9600 baud
  panservo.attach(2);  // attaches the pan servo on pin 2 to the servo object 
  tiltservo.attach(3); // attaches the tilt servo on pin 3 to the servo object
  panservo.write(0);  //reset servos to 0 position
  tiltservo.write(0);
  delay(500);          //wait for the servos to go to 0
  
} 
void(* resetFunc) (void) = 0; //declare reset function @ address 0

 
void loop() 
{ 
  if(Serial){
    for(panpos = 0; panpos <= 16; panpos += 2){  // goes from 0 degrees to 180 degrees                                
      panservo.write(panpos);              // tell servo to go to position in variable 'panpos'
      delay(150);                       // waits 150 ms for the servo to reach the position 
  
     for(tiltpos = 0; tiltpos<=80; tiltpos+= 2)     // goes from 180 degrees to 0 degrees 
     {                                
        tiltservo.write(tiltpos);              // tell servo to go to position in variable 'tiltpos' 
        delay(150);                       // waits 150 ms for the servo to reach the position 
        range = analogRead(0);   //read distance sensor
        Serial.println(String(panpos)+index+String(tiltpos)+index+String(range)); //write data to file
        if(panpos == 16 && tiltpos == 80){ //if done, print end to serial and reset arduino
          Serial.println("end");
          delay(1500);
          resetFunc(); 

        }
    }  
   }
  }   
} 
