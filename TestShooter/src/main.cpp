#include <Arduino.h>
int test = 20;
void setup() {
  pinMode(test,INPUT);
  // put your setup code here, to run once:
}

void loop() {
  Serial.println(digitalRead(test));
  // put your main code here, to run repeatedly:
}