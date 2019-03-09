#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  myservo.attach(5);
  delay(5000);  // attaches the servo on pin 9 to the servo object
}

void loop() {
   // goes from 0 degrees to 180 degrees
    // in steps of 1 
    pos = 115;
    myservo.write(pos);
    Serial.println(pos);              // tell servo to go to position in variable 'pos'
    delay(500);
    pos = 90;
    myservo.write(pos);
    delay(500);                       // waits 15ms for the servo to reach the position
 
}