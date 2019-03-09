#include <Arduino.h>
int switching = 6;
int flag = 0;
void setup() {
  Serial.begin(9600);
  pinMode(switching,OUTPUT);

  // put your setup code here, to run once:
}

void loop() {

if(Serial.available()){
    // Serial.println("");
    char keyPress = Serial.read();
    Serial.println("Direction changed---Pressed Key:");
    Serial.println(keyPress);
    if(flag) {
      flag=0;
      digitalWrite(switching,LOW);
    }
    else {
      digitalWrite(switching,HIGH);
    flag=1;
  }
}

  // put your main code here, to run repeatedly:
}