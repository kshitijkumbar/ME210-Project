#include <Arduino.h>

int motorLeft1 = 9;
int motorLeft2 = 10;
int motorRight1 = 3;
int motorRight2 = 4 ;
int avgSpeed = 60;

//Attachment for TapeSensor phototransistors
int leftReading = 16;
int rightReading = 15;
int centerReading = 17;

//Initializing thresholds
int LRThreshold = 0;
int RRThreshold = 0;
int CRThreshold = 0;

//Stepper
int step = 18;
int dir = 19;
int switchh = 6;



void setup() {


pinMode(motorLeft1,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight2,OUTPUT);
  pinMode(leftReading,INPUT);
  pinMode(rightReading,INPUT);
  pinMode(centerReading,INPUT);
  pinMode(step,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(switchh,OUTPUT);

digitalWrite(switchh,LOW);
digitalWrite(dir,LOW);
digitalWrite(step,LOW);

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

  // put your setup code here, to run once:
}

void loop() {

// Serial.println("Limit Switch Values");
  // Serial.println(LimitSwitchDetected);
  // Serial.print("Center: ");
  // Serial.println(analogRead(centerReading));
  //   Serial.print("Left: ");
  // Serial.println(analogRead(leftReading));
  //   Serial.print("Right: ");
  // Serial.println(analogRead(rightReading));
  // delay(500);

  //  Serial.println("Motor Moving");
  analogWrite(motorLeft2,avgSpeed);
  analogWrite(motorLeft1,0);    
  analogWrite(motorRight2,avgSpeed);
  analogWrite(motorRight1,0); 

  // put your main code here, to run repeatedly:
}