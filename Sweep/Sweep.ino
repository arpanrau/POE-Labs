// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo panservo; 
Servo tiltservo;// create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int panpos = 0;    // variable to store the servo position 
int tiltpos = 0;   

 
 
void setup() 
{ 
  Serial.begin(9600);
  panservo.attach(2);  // attaches the servo on pin 9 to the servo object 
  tiltservo.attach(3);
  panservo.write(0);
  tiltservo.write(0);
} 
 
 
void loop() 
{ 
  for(panpos = 0; panpos < 180; panpos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    panservo.write(panpos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position 

   for(tiltpos = 0; tiltpos<=100; tiltpos+=1)     // goes from 180 degrees to 0 degrees 
   {                                
      tiltservo.write(tiltpos);              // tell servo to go to position in variable 'pos' 
      delay(50);                       // waits 15ms for the servo to reach the position 
  }  
 }   
} 
