//Attempting to create functions for 5 different modes, and a choose function to switch between these 5 modes by adding incrementally 

int current_state = 0; //This variable will be used to toggle through the 5 modes/states
const int pinLED1 = 13; //Red LED
const int pinLED2 = 12; //Yellow LED
const int pinLED3 = 11; //Green LED
const int pinButton = 8; //Push Button 
unsigned long lastDebounceTime = 0; //the last time the output pin was toggled 
unsigned long debounceDelay = 200; // the debounce time, increase if the output flickers 

// the setup function runs once when you press reset or power the board 
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(pinLED1, OUTPUT);
  
  // initialize next digital pin 12 as an output.
  pinMode(pinLED2, OUTPUT);

  // initialize next digital pin 11 as an output.
  pinMode(pinLED3, OUTPUT);

  // initialize button pin as an input 
  pinMode(pinButton, INPUT) 
  
  //Make arduino talk to the computer
  Serial.begin(9600);
}

void loop() { 
 //HERE WE WILL CALL ALL 5 FUNCTIONS AND INCREMENTALLY SWITCH BETWEEN USING COUNTER (CHANGE CURRENT STATE)
 
 // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

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
    if (reading != buttonState) {
      buttonState = reading; //creates new current state

      // only toggle LED functions if the new button state is HIGH
      if (buttonState == HIGH) {
        current_state = current_state + 1;
      }
    } 
  }

  //NESTED LED FUNCTIONS HERE

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

void AllOff() {
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinlED2, LOW);
  digitalWrite(pinLED3, LOW);
}
void AllFlashing() {


  lastBlinkTime = millis();
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinlED2, HIGH);
  digitalWrite(pinLED3, HIGH);
  
  if ((millis() - 
  
}
void AllOn() {
  
}
void BlinkInOrder() {
  
}
void BlinkAlternating() {
  
}

