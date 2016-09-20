

int current_state = 0; //This variable will be used to toggle through the 5 led modes/states
const int pinLED1 = 13; //Red LED
const int pinLED2 = 12; //Yellow LED
const int pinLED3 = 11; //Green LED
const int pinButton = 8; //Push Button 
unsigned long lastDebounceTime = 0; //the last time the output pin was toggled 
unsigned long debounceDelay = 10; // the debounce time, increase if the output flickers 
int lastButtonState = 0; //last Button State
int ButtonState = 0; //Button State
unsigned long lastBlinkTime = 0; //last time that the LED blinked or changed states within an LED control function
int analogPin = 0; //pin to read distance sensor
int val_read = 0; //value read from distance sensor


void setup() {
  // initialize digital pin 13 as an output.
  pinMode(pinLED1, OUTPUT);
  
  // initialize next digital pin 12 as an output.
  pinMode(pinLED2, OUTPUT);

  // initialize next digital pin 11 as an output.
  pinMode(pinLED3, OUTPUT);
  
  //Make arduino talk to the computer
  Serial.begin(9600);
}

void loop() { 

//This structure chooses what to set current_state based on the value of the distance sensor. Values chosen experimentally. 
  val_read = analogRead(analogPin);
  if (val_read <= 150){
    current_state = 0;
  }
  else if (val_read <= 250){
    current_state = 1;
  }
  else if (val_read <= 350){
    current_state = 2;
  }
  else if (val_read <= 450){
    current_state = 3;
  }
  else {
    current_state = 4;
  }

//Calls LED function based on Current state
  if (current_state == 0){
    AllOff();  
  }
  if (current_state == 1){
    AllFlashing();
  }
  if (current_state == 2){
    AllOn();
  }
  if (current_state == 3){
    BlinkInOrder();
  }
  if (current_state == 4){
    BlinkAlternating();
  }
  

  // save the last state.  Next time through the loop,
  // it'll be the lastButtonState:
  if(lastButtonState != current_state){
    lastDebounceTime = millis();
  }
  //Update current state 
  lastButtonState = current_state;
  //
  Serial.println(val_read);
}

void AllOff() {
  //Turns all the LEDS off
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
}
void AllFlashing() {
   //Checks mills and does a mod to see whether in an odd or even time since pattern last changed. If odd, turns off. if even, turns on.
  if ((((millis()-lastDebounceTime)/1000) % 2) == 1  ){
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, HIGH);
  }
  else {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, LOW);
  }  
  
  
}
void AllOn() {
  //Turns all the LEDs on
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED3, HIGH); 
}
void BlinkInOrder() {
   //Checks mills and does a mod to see which led should be on.
  if ((((millis()-lastDebounceTime)/1000) % 3) == 0  ){
    digitalWrite(pinLED1, HIGH);
  }
  else {
    digitalWrite(pinLED1, LOW);
    
  }  
    if ((((millis()-lastDebounceTime)/1000) % 3 ) == 1 ){
    digitalWrite(pinLED2, HIGH);
  }
  else {
    digitalWrite(pinLED2, LOW);
  }  

    if ((((millis()-lastDebounceTime)/1000) % 3 ) == 2  ){
    digitalWrite(pinLED3, HIGH);
  }
  else {
    digitalWrite(pinLED3, LOW);
  }  
    
}
void BlinkAlternating() {
  //Checks millis and does a mod. Turns on one LED and then the other two, alternating.
  if ((((millis()-lastDebounceTime)/1000) % 2) == 1  ){
    digitalWrite(pinLED1, HIGH);
    digitalWrite(pinLED2, LOW);
    digitalWrite(pinLED3, HIGH);
  }
  else {
    digitalWrite(pinLED1, LOW);
    digitalWrite(pinLED2, HIGH);
    digitalWrite(pinLED3, LOW);
  }  
 
}

