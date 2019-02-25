#include <Arduino.h>


// Attach TapeSensor emitters between supply and ground
//Attachment for TapeSensor phototransistors
int leftReading = 16;
int rightReading = 17;
int centerReading = 18;
//Motor Connections to Teensy
int motorLeft1 = 3;
int motorLeft2 = 4;
int motorRight1 = 10;
int motorRight2 = 9;
//Initializing thresholds
int LRThreshold = 0;
int RRThreshold = 0;
int CRThreshold = 0;
int avgSpeed = 125;
//Proportional gain value (to be tuned)
int Kp = 2;


void setup() {
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight2,OUTPUT);
  pinMode(leftReading,INPUT);
  pinMode(rightReading,INPUT);
  pinMode(centerReading,INPUT);
  
  //Initialize the sensors
  Serial.println("Calibrating Threshold in 5 seconds");
  delay(5000); 
  int i = 0;

  //Initializing the threshold values for the three tape sensors
  //
  for(i=0;i<100;i++) { 
  CRThreshold = CRThreshold + analogRead(centerReading);
  RRThreshold = RRThreshold + analogRead(rightReading);
  LRThreshold = LRThreshold + analogRead(leftReading);

  }
  CRThreshold = (CRThreshold/100);
  RRThreshold = (RRThreshold/100);
  LRThreshold = (LRThreshold/100);


  Serial.println("Printing Threshold values : L C R");
  Serial.println(LRThreshold);
  Serial.println(CRThreshold);
  Serial.println(RRThreshold);
  Serial.begin(9600);
  delay(5000);

  Serial.println("Motor Moving");
  analogWrite(motorLeft1,avgSpeed);
  analogWrite(motorLeft2,0);    
  analogWrite(motorRight1,avgSpeed);
  analogWrite(motorRight2,0);    

}

void loop() {

  // //Calculate error
  int CError = CRThreshold - analogRead(centerReading);
  int RError = RRThreshold - analogRead(rightReading);
  int LError = LRThreshold - analogRead(leftReading);
  
  //Commented out the debugging code for sensor value readings
  
  // Serial.print("Center: ");
  // Serial.println(analogRead(centerReading));
  //   Serial.print("Left: ");
  // Serial.println(analogRead(leftReading));
  //   Serial.print("Right: ");
  // Serial.println(analogRead(rightReading));
  // delay(500);

//Code for running Proportional controller

  if(abs(CError)>100 ){
    Serial.println("Away for Center");
    if(abs(RError)>abs(LError)&& abs(RError)>100 ){
       Serial.println("Right Error");
      int gainSpeed= Kp*RError;
      analogWrite(motorLeft1,avgSpeed + gainSpeed);
      analogWrite(motorLeft2,0);    
      Serial.println(avgSpeed + gainSpeed);
      analogWrite(motorRight1,avgSpeed - gainSpeed);
      Serial.println(avgSpeed - gainSpeed);
      analogWrite(motorRight2,0);
    }
    else if(abs(RError)<abs(LError) && abs(LError)>100){
      // Serial.println("LEFT Error");
      int gainSpeed= Kp*LError;
      analogWrite(motorLeft1,avgSpeed - gainSpeed);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,avgSpeed + gainSpeed);
      analogWrite(motorRight2,0);

    }


   } else{

     Serial.println("Center");
   }
  // put your main code here, to run repeatedly:
}