// Names: Victoria Przydanek, Jishnuu Senthil Kumar, Digonto Chatterjee
// Date: 11.02.2025
// Description: Making a page turner for soft cover books/flimsy pages
// Updates: We wanted to test out the hardware, so we included a button that isn't
// the headphone jack but a simple button for implementing and testing.


// importing libraries
#include <Servo.h>

// defining variables
const int servoPin = 6;  // initializing servo
Servo pageTurner;        // create servo object

//Motor Control
const int ENA_PIN = A5;  // Speed control
// *MIGHT CHANGE THE TIME = SPEED CONSTANT LATER*
const int time = 500;   // how long servo waits for motor to run before it turns the page
const int speed = 200;  // how fast the servo was moving

const int buttonPin = 7;
int buttonPress;  // set to False so the statement doesn't run continuously

void setup() {
  pageTurner.attach(servoPin);  // connect servo signal wire to Arduino Pin
  pageTurner.write(0);          // get the servo to be in the neutral position

  pinMode(ENA_PIN, OUTPUT);

  pinMode(buttonPin, INPUT);  // declaring the button pin

  Serial.begin(9600);
}

void loop() {
  buttonPress = digitalRead(buttonPin);  // sets variable to button pin reading
  // Serial.println(buttonPress); // debugs
  if (buttonPress==LOW) {
    Serial.println("I am working!");  // debugs
    // M O T O R A C T I V A T I O N
    analogWrite(ENA_PIN, speed);  // lets us control how fast the motor is spinning
    delay(time);                  // determines how long we want to have the wheel turn
    analogWrite(ENA_PIN, 0);
    // S E R V O M O V E M E N T
    for (int i = 0; i < 180; i++) {  // this slows down the servo's run to prevent pages from breaking
                                     // *MIGHT HAVE TO CHANGE LATER IF IT IS RUNNING TOO SLOW*
      pageTurner.write(i);
      delay(3);
    }
    // page has been turned
    pageTurner.write(0);  // return servo to original position
  }
}
