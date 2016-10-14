/*
 * LineFollowerBot
 * Loosely based on PID 
 * Sara Ballantyne
 */
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

String index = ","; //index for output string

//Variables that will change:
int targetLeft; //Upon initializing, write left sensor value to targetLeft
int targetRight; //Upon initializing, write right sensor value to targetRight
float P = 9;
int sensorValueL;
int sensorValueR;
int dist1;
int dist2;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port'. In this case, M3
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(3);
// Make another motor on port M4
Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(4);

void setup() {
  // put your setup code here, to run once:
  delay(500);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  targetLeft = analogRead(A0);
  targetRight = analogRead(A1); 
//  Serial.println(String(targetLeft));
  
  
  delay(500); //delay to initialize and get hands out of the way
  AFMS.begin();  // create with the default frequency 1.6KHz

  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotorLeft->setSpeed(50);
  myMotorRight->setSpeed(50);
  myMotorLeft->run(FORWARD);
  myMotorRight->run(FORWARD);
  // turn on motors
  myMotorLeft->run(RELEASE);
  myMotorRight->run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
 // read the input on analog pin 0 and 1:
  sensorValueL = analogRead(A0);
  sensorValueR = analogRead(A1); 
  
if (Serial.available() > 0) {
  // read the incoming byte:
  P = Serial.parseFloat();
}
  
  myMotorLeft->run(FORWARD);
  dist1 = 30 - (sensorValueL - targetLeft)/P;
  if (dist1 < 0) {
  dist1 = 0;
  }
   myMotorLeft->setSpeed(dist1); 

  myMotorRight->run(FORWARD);
  dist2 = 30 - (sensorValueR - targetRight)/P;
  if (dist2 < 0) {
  dist2 = 0;
  }
  myMotorRight->setSpeed(dist2);

Serial.println(String(targetLeft) + index + String(targetRight)+ index + String(sensorValueL) + index + String(sensorValueR) +  index + String(dist1) + index +  String(dist2) + index + String(P)); 
  delay(10);        // delay in between sensor reads for stability
}
