#include <Arduino.h>
#include <Chrono.h>


/*---------------Module Defines-----------------------------*/
#define TIMER_ARMOURY_REVERSE            2000 //Set reverse timer based on experiment
#define TIMER_ARMOURY_TURNCW            0 //Set clockwise turn timer based on experiment
#define TIMER_ARMOURY_TURNCCW            0 //Set counterclockwise turn timer based on experiment
#define TIMER_ARMOURY_BACKOUT            0 //Set backout timer based on experiment

/*---------------Module Function Prototypes-----------------*/
void initialise(void);
void checkGlobalEvents(void);
void moveTowardsArmoury(void);
void ReverseInArmoury(void);
void RespReverseTimerExpired(void);
void TurnCWInArmoury(void);
void RespTurnCWTimerExpired(void);
void TurnCCWInArmoury(void);
void RespTurnCCWTimerExpired(void);
bool DetectedArmoury(void);
void ShootingCastRock(void);
void KeyIn (void);
void StoppedInArmoury(void);
/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_MOVE_TOWARD_AROMOURY, STATE_DETECTED_ARMOURY,STATE_REVERSE_IN_AROMOURY,STATE_TURNCW_IN_AROMOURY,STATE_TURNCCW_IN_AROMOURY
  ,STATE_BACKOUT_ARMOURY, STATE_SHOOT_CASTROCK, STATE_PRESS_FORWARD,STATE_PRESS_REVERSE
} States_t;

/*---------------Module Variables---------------------------*/
States_t state;

//Declaring Timers (ONLY TWO TIMERS WORK SIMULTANEOUSLY)
IntervalTimer armouryReversal;
IntervalTimer armouryTurnCW;
IntervalTimer armouryTurnCCW;
IntervalTimer armouryBackout;

// Attach TapeSensor emitters between supply and ground
//Attachment for TapeSensor phototransistors
int leftReading = 16;
int rightReading = 17;
int centerReading = 18;
//Motor Connections to Teensy
int motorLeft1 = 10;
int motorLeft2 = 9;
int motorRight1 = 3;
int motorRight2 = 4;
//Initializing thresholds
int LRThreshold = 0;
int RRThreshold = 0;
int CRThreshold = 0;
int avgSpeed = 125;
//Proportional gain value (to be tuned)
double Kp = 0.50;
//Flag to kill motors
int flag = 0;
int line_counter = 0;

//Detectors
int armouryDetected=0;

//US Sensor
int trigPin = 19;
int echoPin = 20;
long duration, cm;
 

void setup() {
  //Set Pin State
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight2,OUTPUT);
  pinMode(leftReading,INPUT);
  pinMode(rightReading,INPUT);
  pinMode(centerReading,INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
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
state = STATE_MOVE_TOWARD_AROMOURY;
}

void loop() {

checkGlobalEvents();
  //following switch case handles the state motions
  switch (state) {
    case STATE_MOVE_TOWARD_AROMOURY:
      moveTowardsArmoury();
      break;
    case STATE_DETECTED_ARMOURY:
      StoppedInArmoury();
      break;
    case STATE_REVERSE_IN_AROMOURY:
      ReverseInArmoury();
      break;
    default:    // Should never get into an unhandled state
      Serial.println("What is this I do not even...");
  }
}

//   //Code for keypress stop
//  if(Serial.available()){
//     // Serial.println("");
//     char keyPress = Serial.read();
//     Serial.println("Direction changed---Pressed Key:");
//     Serial.println(keyPress);
//     if(flag) {
//       flag=0;
//     }
//     else {
//     flag=1;
//   }
//  }
//  //Loop to Stop motors if keypress flag is true. Will exit loop when key is pressed again
//   while(flag) {
//     Serial.println("STOP!!!!!!!!");
//      analogWrite(motorLeft1,0);
//       analogWrite(motorLeft2,0);    
//       analogWrite(motorRight1,0);
//       analogWrite(motorRight2,0);
//       Serial.println(avgSpeed);
//      if(Serial.available()){
//     // Serial.println("");
//     char keyPress = Serial.read();
//     Serial.println("Direction changed---Pressed Key:");
//       flag=0;
  
//   }
//   }

void checkGlobalEvents() {
  if(DetectedArmoury&& !armouryDetected) {
    armouryDetected = 1; //Remember to change when exiting Armoury
    armouryReversal.begin(RespReverseTimerExpired,TIMER_ARMOURY_REVERSE);
    state = STATE_DETECTED_ARMOURY;
    }

  }
void StoppedInArmoury() {
  Serial.println("Stopped, Wall sensed");
  state = STATE_REVERSE_IN_AROMOURY;

}
void moveTowardsArmoury() {
  Serial.println("GOING");
  //Actual P control code for Motor
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


  if(abs(CError)>100 ){
      // Serial.println("Away from center");
      
      if(abs(RError)>abs(LError)&& abs(RError)>100 ){
        //  Serial.println("Right Error");
        int gainSpeed= abs(Kp*RError);
              // Serial.println("Gain Speed");
        // Serial.println(gainSpeed);
        analogWrite(motorLeft1,avgSpeed + gainSpeed);
        analogWrite(motorLeft2,0);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,avgSpeed - gainSpeed);
        // Serial.println(avgSpeed - gainSpeed);
        analogWrite(motorRight2,0);
        // Serial.println("Speed for motors:");
        // Serial.println(avgSpeed + gainSpeed);
        // Serial.println(avgSpeed - gainSpeed);

      }
      else if(abs(RError)<abs(LError) && abs(LError)>100){
        //  Serial.println("LEFT Error");
        int gainSpeed= abs(Kp*LError);
        // Serial.println("Gain Speed");
        // Serial.println(gainSpeed);
        analogWrite(motorLeft1,avgSpeed - gainSpeed);
        analogWrite(motorLeft2,0);    
        analogWrite(motorRight1,avgSpeed + gainSpeed);
        analogWrite(motorRight2,0);
        // Serial.println("Speed for motors:");
        // Serial.println(avgSpeed + gainSpeed);
        // Serial.println(avgSpeed - gainSpeed);
      }

  }
    else{

    //  Serial.println("Center");
     analogWrite(motorLeft1,avgSpeed);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,avgSpeed);
      analogWrite(motorRight2,0);
      // Serial.println(avgSpeed); 
    } 


}
void RespReverseTimerExpired() {
  armouryReversal.end();
  state = STATE_TURNCW_IN_AROMOURY;
  // armouryTurnCW.begin(RespTurnCWTimerExpired,TIMER_ARMOURY_TURNCW);
}
// void RespTurnCWTimerExpired() {
//    armouryTurnCW.end();
//   state = STATE_TURNCW_IN_AROMOURY;
//   armouryTurnCW.begin(RespTurnCWTimerExpired,TIMER_ARMOURY_TURNCW);
// }

void ReverseInArmoury() {
  Serial.println("Motor Reversing");
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,avgSpeed);    
  analogWrite(motorRight1,0);
  analogWrite(motorRight2,avgSpeed); 
}

bool DetectedArmoury() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration/2)/29.1;
    if (cm < 10) {
      // Serial.println("STOP!!!!!!!!");
      analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,0);
      analogWrite(motorRight2,0);
      return true;  
    }
    else { return false;}


}
