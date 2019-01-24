/*
 *
 *  Behavior:
 *  On power up the LEDs will blink 5 times meaning that all of the LEDs are working, this is the ledInit function running.
 *  On the first button press (in theory if not caught up by the dealy functions that I couldn't find a clean way to get around) the leds will wave from right to left, with the speed of the animation being controlled by the pot.
 *  Upon the second button press, you will be able to control which LED's are lit up based on the position of the pot. This is explained further in the code in the form of comments.
 *  Finally, of the thrid button press there will be a wave animation of the LEDs, going from outside to inside then back to outside, once again, the speed of this animation will be controlled by the postiion of the pot.
 */

//Defining the pins that are needed.
const int potPin = A5;
const int ledPin[] = {2,3,4,5,6,7};
const int buttonPin = 8;

//A varible for counting what animation the program is currently on.
int buttonCount = 0;

//A bool for checking if the led initialization has ran yet.
bool initRan = false;

//A function that workes to clear all of the leds, used after led initalization and after button cycle 3.
void clearLeds(){
  //Sets all of the LEDs to low.
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[4], LOW);
  digitalWrite(ledPin[5], LOW);
}

//A function for initalizing the leds. This blinks the LEDs 5 times.
void ledInit(){
  for(int i = 0; i < 5; i++){
    delay(100);
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
    delay(100);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(100);
  }
}

//A function for the first animation, this animation waves through all of the LEDs with the delay being controlled by the pot.
void animationOne(int delaySpeed){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], HIGH);
    delay(delaySpeed);
}


//A function for the second animation, this one changes which LEDs is lit by the position of the pot.
void animationTwo(int ledSelector){
  //To make the input from the pot easier to work with, we map it to a new variable with a range of 0 to 4.
  int mappedLedSelector = map(ledSelector, 10, 500, 0, 4);

  //If the pot position is at 0, then the 1st and 6th LEDs will light up.
  if(mappedLedSelector == 0){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], HIGH);
    delay(100);
  }

  //If the pot position is at 1, then the 2nd and 5th LEDs will light up.
  else if(mappedLedSelector == 1){
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], LOW);
    delay(100);
  }

  //If the pot position is at 2, then the 3rd and 4th LEDs will light up.
  else if(mappedLedSelector == 2){
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(100);
  }

  //If the pot position is at 3 then all of the LEDs will light up.
  else if(mappedLedSelector == 3){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
    delay(100);
  }

  //If the pot position is at 4 then all of the LED's will blink on and off.
  else if(mappedLedSelector == 4){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
    delay(100);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(100);
  }
}


//A function for the third animation, which waves the LED's from outside to inside, then in to out. With the delay being controlled by the pot.
void animationThree(int delaySpeed){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], HIGH);
    delay(delaySpeed);
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
    delay(delaySpeed);
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], HIGH);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], HIGH);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    delay(delaySpeed);
}


void setup() {
  //Setting up all of the LEDs be outputs.
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  pinMode(ledPin[5], OUTPUT);

  //Setting up the button as an input using the Arduino's built in pullup resistor.
  pinMode(buttonPin, INPUT_PULLUP);

  //Starting serial communication using 9600 baud.
  Serial.begin(9600);
  Serial.println("*** Press the button to run the animations... ***");
}

void loop() {
  
  //If the led init has not ran yet, then it will and the bool will be set to true meaning that it has ran.
  if(initRan == false){
    //Run the ledInit function.
    ledInit();
    //Sets the bool to true.
    initRan = true;
  }
  
  //Pot loop setup.
  int potVal = analogRead(potPin);
  //NOTE: The range of the pot is 0-1023.
  //Mapping the value range of the pot to a more reasonable range of 0 to 500.
  int mappedPotVal = map(potVal, 0, 1023, 10, 500);

  //Button loop setup.
  int buttonVal = digitalRead(buttonPin);
  //Checks to see if the button is pressed.
  if(buttonVal == LOW){
    //If the buttonCount is 4 then the count will be reset to 0.
    if(buttonCount == 4){
      buttonCount = 0;
    }
    //Otherwise increment the buttonCount.
    else{
      buttonCount++;
    }
  }
  /*
   * Here I really could have used a switch statement but I really do not like them and as such I just went with a messy looking if/else if statement.
   * -A Moderate Rant by Graham
   */
  
  //Checking to see what iteration the buttonCount is on and running the appropriate animation.
  if(buttonCount == 0){
    //Ensures that all of the LEDs are turned off.
    clearLeds();
  }
  else if(buttonCount == 1){
    //Calls the animationOne function with the mappedPotVal.
    animationOne(mappedPotVal);
  }
  else if(buttonCount == 2){
    //Calls the animationTwo function with the mappedPotVal.
    animationTwo(mappedPotVal);
  }
  else if(buttonCount == 3){
    //Calls the animationThree function with the mappedPotVal.
    animationThree(mappedPotVal);
  }
  delay(100);
}
