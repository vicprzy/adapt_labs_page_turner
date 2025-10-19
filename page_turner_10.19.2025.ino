// Names: Victoria Przydanek, Jishnuu Senthil Kumar, Digonto Chatterjee
// Date: 10.19.2025
// Description: Making a page turner for soft cover books/flimsy pages 


// importing libraries
#include <Servo.h>

// defining variables 
const int servoPin = 6;  // initializing servo
Servo pageTurner;  // create servo object

const int motorPin = 4;  // initializing motor
// *MIGHT CHANGE THE TIME CONSTANT LATER*
const int time = 500;  // how long servo waits for motor to run before it turns the page

const int buttonPin = 7;
bool buttonPress = False;  // set to False so the statement doesn't run continuously

void setup() {
  pageTurner.attach(servoPin);  // connect servo signal wire to Arduino Pin
  pageTurner.write(0);  // get the servo to be in the neutral position

  pinMode(motorPin, OUTPUT);  // to take signals from the arduino
  digitalWrite(motorPin, LOW);  // turning off motor
}

void loop() {
  if (buttonPress){
    // M O T O R A C T I V A T I O N
    digitalWrite(motorPin, HIGH);  // lets the wheel start spinning 
    delay(time);  // determines how long we want to have the wheel turn
    digitalWrite(motorPin, LOW);  // wheel moved enough of page for servo to get under
    // S E R V O M O V E M E N T
    for (int i = 0; i < 180; i++){  // this slows down the servo's run to prevent pages from breaking
    // *MIGHT HAVE TO CHANGE LATER IF IT IS RUNNING TOO SLOW*
      pageTurner.write(i);
      delay(3);
    }
    // page has been turned 
    pageTurner.write(0);  // return servo to original position
  }

}
