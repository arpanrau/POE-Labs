//Attempting to create functions for 5 different modes, and a choose function to switch between these 5 led modes by adding incrementally 

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

// the setup function runs once when you press reset or power the board 
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(pinLED1, OUTPUT);
  
  // initialize next digital pin 12 as an output.
  pinMode(pinLED2, OUTPUT);

  // initialize next digital pin 11 as an output.
  pinMode(pinLED3, OUTPUT);

  // initialize button pin as an input 
  pinMode(pinButton, INPUT); 
  
  //Make arduino talk to the computer
  Serial.begin(9600);
}

void loop() { 
 //HERE WE WILL CALL ALL 5 FUNCTIONS AND INCREMENTALLY SWITCH BETWEEN USING COUNTER (CHANGE CURRENT STATE)
 
 // read the state of the switch into a local variable:
  int reading = digitalRead(pinButton);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis(); //time in milliseconds
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != ButtonState) {
      ButtonState = reading; //creates new current state

      // only toggle LED functions if the new button state is HIGH
      if (ButtonState == HIGH) {
        if (current_state <= 3) {
          current_state = current_state + 1;
        }
        else {
          current_state = 0;
        }
      }
    }
  }

  //NESTED LED FUNCTIONS HERE
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
  

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  
  lastButtonState = reading;
 

}

void AllOff() {
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
}
void AllFlashing() {
  
  
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
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED3, HIGH); 
}
void BlinkInOrder() {
  
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

