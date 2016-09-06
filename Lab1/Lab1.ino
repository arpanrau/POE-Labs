/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
//Attempting to create functions for 5 different modes, and a choose function to switch between these 5 modes 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  
  // initialize next digital pin 12 as an output.
  pinMode(12, OUTPUT);

    // initialize next digital pin 11 as an output.
  pinMode(11, OUTPUT);
}

void loop() {
 for (i = 1){
  myBlinkInOrderFunction();
 }
 for (i = 2) {
  Function2();
 
 for 
  
}

void myBlinkInOrderFunction() {
  void loop() {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(500);              // wait for a second
   
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second
  
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
    delay(1500);              // wait for a second
    }
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
 
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second

  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(1500);              // wait for a second
}
