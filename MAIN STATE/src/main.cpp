#include <Arduino.h>
#include <Servo.h>

/*---------------Module Defines-----------------------------*/
#define TIMER_ARMOURY_REVERSE            700000 //Set reverse timer based on experiment
#define TIMER_ARMOURY_TURNCW             1000000 //Set clockwise turn timer based on experiment2000000 
#define TIMER_TOWARD_SWITCH              1000000 //Set timer to go to switch
#define TIMER_AWAY_SWITCH                1000000 //Set timer to go to switch
#define TIMER_ARMOURY_TURNCCW            1000000 //Set counterclockwise turn timer based on experiment
#define TIMER_ARMOURY_SHOOTING_POSITION  1500000 //Set backout timer based on experiment
#define TIMER_CENT                       7500000 //Set backout timer based on experiment

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
void KeyIn (void);
void StoppedInArmoury(void);
void moveAwayFromArmoury(void);
void  ForwardInArmoury(void); 
void ReturnToLineInArmoury(void); 
void moveAwayFromArmoury(void);
void ShootingCastRock(void);
void RespTowardSwitchTimerExpired(void);
void RespAwaySwitchTimerExpired(void);
void RespShootPositionExpired(void);
void RespAwayLineSensed(void);
void InitCastRock(void);
void stopE(void);
/*---------------State Definitions--------------------------*/
typedef enum {
  STATE_MOVE_TOWARD_ARMOURY, STATE_DETECTED_ARMOURY,STATE_REVERSE_IN_ARMOURY,STATE_TURNCW_IN_ARMOURY,STATE_MOVE_TOWARD_SWITCH
  ,STATE_MOVE_AWAY_SWITCH,STATE_TURNCCW_IN_ARMOURY,STATE_MOVE_AWAY_ARMOURY, STATE_SHOOT_CASTROCK, STATE_AT_CASTROCK_POS,STATE_STOP
} States_t;

/*---------------Module Variables---------------------------*/
States_t state;

//Declaring Timers (ONLY TWO TIMERS WORK SIMULTANEOUSLY)
IntervalTimer armouryReversal;
IntervalTimer armouryTurnCW;
IntervalTimer armouryTowardSwitchTimer;
IntervalTimer armouryAwaySwitchTimer;
IntervalTimer armouryTurnCCW;
IntervalTimer ShootingPosition;
IntervalTimer centerFind;

//Servo attach

Servo myservo;

//Stepper Motor
int step = 18;
int dir = 19;

//Time
int init_time = 0;

// Attach TapeSensor emitters between supply and ground
//Attachment for TapeSensor phototransistors
int leftReading = 16;
int rightReading = 15;
int centerReading = 17;
//Motor Connections to Teensy
  int motorLeft1 = 9;
int motorLeft2 = 10;
int motorRight1 = 3;
int motorRight2 = 4 ;
//Initializing thresholds
int LRThreshold = 0;
int RRThreshold = 0;
int CRThreshold = 0;
int avgSpeed = 100;
int avgSpeed2 = 60;
//Proportional gain value (to be tuned)
double Kp = 0.50;
double Kp2 = 0.40;

//Flag to kill motors
int flag = 0;
int line_counter = 0;
int center = 0;
int centFlag=0;
//Detectors
int armouryDetected=0;
int limSwitch=2;
int LimitSwitchDetected=1;//WOrks the other way, i.e. 0 --> Contact!
int shooterSwitch = 6;
int shooterSwitchFlag = 0;
int stopperCounter = 0;
int pos = 90; 
//US Sensor
// int trigPin = 19;
// int echoPin = 20;
// long duration, cm;
 

void setup() {
  //Set Pin State
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight2,OUTPUT);
  pinMode(leftReading,INPUT);
  pinMode(rightReading,INPUT);
  pinMode(centerReading,INPUT);
  pinMode(shooterSwitch,OUTPUT);
  pinMode(step,OUTPUT);
  pinMode(dir,OUTPUT);

  digitalWrite(shooterSwitch,LOW);
  digitalWrite(dir,LOW);
  digitalWrite(step,LOW);
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  pinMode(limSwitch, INPUT_PULLUP);
  myservo.attach(5);
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
  // delay(10000);   
state = STATE_MOVE_TOWARD_ARMOURY;
init_time = millis();
// state = STATE_MOVE_AWAY_ARMOURY;
// state  = STATE_AT_CASTROCK_POS;
}

void loop() {
  int current_time = millis();
  if((current_time-init_time) >110000){
    state = STATE_STOP;
  }
  
   if(Serial.available()){
    // Serial.println("");
    char keyPress = Serial.read();
    Serial.println("Direction changed---Pressed Key:");
    Serial.println(keyPress);
    if(flag) {
      flag=0;
    }
    else {
    flag=1;
  }
 }
   while(flag) {
    Serial.println("STOP!!!!!!!!");
     analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,0);
      analogWrite(motorRight2,0);
      Serial.println(avgSpeed);
     if(Serial.available()){
    // Serial.println("");
    char keyPress  = Serial.read();
    Serial.println("Direction changed---Pressed Key:");
      flag=0;
  
  }
  }

  //  while(true) {
  // //     LimitSwitchDetected = digitalRead(limSwitch);
  // // Serial.println("Limit Switch Values");
  // // Serial.println(LimitSwitchDetected);
  // Serial.print("Center: ");
  // Serial.println(analogRead(centerReading));
  //   Serial.print("Left: ");
  // Serial.println(analogRead(leftReading));
  //   Serial.print("Right: ");
  // Serial.println(analogRead(rightReading));
  // delay(500);
  //   // digitalWrite(trigPin, LOW);
  //   // delayMicroseconds(5);
  //   // digitalWrite(trigPin, HIGH);
  //   // delayMicroseconds(10);
  //   // digitalWrite(trigPin, LOW);
  //   // duration = pulseIn(echoPin, HIGH);
  //   // cm = (duration/2.0)/29.1;
  //   // Serial.println("----------------------");
  //   // Serial.println(cm);
  //   // Serial.println("----------------------");
  //  }
  checkGlobalEvents();

  //following switch case handles the state motions
  switch (state) {
    case STATE_MOVE_TOWARD_ARMOURY:
      Serial.println("Motor Moving tw Armoury");
      moveTowardsArmoury();
      
      break;
    case STATE_DETECTED_ARMOURY:
      Serial.println("Stopped in Armoury");
      StoppedInArmoury();
      break;
    case STATE_REVERSE_IN_ARMOURY:
    Serial.println("Motor reversing in Armoury");
      ReverseInArmoury();
      break;
    case STATE_TURNCW_IN_ARMOURY:
    Serial.println("Motor turning CW Armoury");
      TurnCWInArmoury();
      break;
    case STATE_MOVE_TOWARD_SWITCH:
    Serial.println("Motor moving tw Switch");
      ForwardInArmoury();
      break;
    case STATE_MOVE_AWAY_SWITCH:
    Serial.println("Motor moving away Switch");
      ReturnToLineInArmoury();
      break;
    case STATE_TURNCCW_IN_ARMOURY:
    Serial.println("Motor turning CCW Armoury");
      TurnCCWInArmoury();
      break;
    case STATE_MOVE_AWAY_ARMOURY:
    Serial.println("Motor moving away Armoury");
      moveAwayFromArmoury();
      break;
    case STATE_AT_CASTROCK_POS:
    Serial.println("SHooting");
      InitCastRock();
      break;
    case STATE_SHOOT_CASTROCK:
    Serial.println("SHooting");
      ShootingCastRock();
      break;

    case STATE_STOP:
    Serial.println("Stopping");
        analogWrite(motorLeft1,0);
        analogWrite(motorLeft2,0);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,0);
        // Serial.println(avgSpeed - gainSpeed);
        analogWrite(motorRight2,0);
      stopE();
      break;

    default:    // Should never get into an unhandled state
      Serial.println("What is this I do not even...");
  }
  // Serial.println("HEREeee");
  // delay(5000);
}
void stopE(){
digitalWrite(shooterSwitch,LOW);
          analogWrite(motorLeft1,0);
        analogWrite(motorLeft2,0);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,0);
        // Serial.println(avgSpeed - gainSpeed);
        analogWrite(motorRight2,0);


}

void checkGlobalEvents() {
  if(!digitalRead(limSwitch) && !armouryDetected) {
    Serial.println("Wall Detected");
    // delay(5000);
    armouryDetected = 1; //Remember to change when exiting Armoury
    armouryReversal.begin(RespReverseTimerExpired,TIMER_ARMOURY_REVERSE);
    state = STATE_DETECTED_ARMOURY;
    // delay(2500);
    Serial.println(state);
    }
    Serial.println(armouryDetected);
  }

void RespToCent() {

centFlag++;
}
void StoppedInArmoury() {
  Serial.println("Stopped, Wall sensed");
  // delay(5000);
  state = STATE_REVERSE_IN_ARMOURY;
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

if(center){if(abs(LError)>500 && abs(CError)<100 && centFlag) {

  Serial.println("HERE!!!!!!!!!");
  delay(300);
          analogWrite(motorLeft1,0);
        analogWrite(motorLeft2,0);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,0);
        // Serial.println(avgSpeed - gainSpeed);
        analogWrite(motorRight2,0);
  state = STATE_AT_CASTROCK_POS;
  centFlag--;
  center--;
  return;
}}
  if(abs(CError)>100 ){
      // Serial.println("Away from center");
      
      if(abs(RError)>abs(LError)&& abs(RError)>100 ){
        //  Serial.println("Right Error");
        int gainSpeed= abs(Kp*RError);
              // Serial.println("Gain Speed");
        // Serial.println(gainSpeed);
        analogWrite(motorLeft1,avgSpeed - gainSpeed);
        analogWrite(motorLeft2,0);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,avgSpeed + gainSpeed);
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
        analogWrite(motorLeft1,avgSpeed + gainSpeed);
        analogWrite(motorLeft2,0);    
        analogWrite(motorRight1,avgSpeed -  gainSpeed);
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
void moveAwayFromArmoury() {
  Serial.println("GOING Backwards");
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
        int gainSpeed= abs(Kp2*RError);
              // Serial.println("Gain Speed");
        // Serial.println(gainSpeed);
        analogWrite(motorLeft1,0);
        analogWrite(motorLeft2,avgSpeed2 - gainSpeed);     
        // Serial.println(avgSpeed + gainSpeed);
        analogWrite(motorRight1,0);
        analogWrite(motorRight2,avgSpeed2 + gainSpeed);
        // Serial.println("Speed for motors:");
        // Serial.println(avgSpeed + gainSpeed);
        // Serial.println(avgSpeed - gainSpeed);

      }
      else if(abs(RError)<abs(LError) && abs(LError)>100){
        //  Serial.println("LEFT Error");
        int gainSpeed= abs(Kp2*LError);
        // Serial.println("Gain Speed");
        // Serial.println(gainSpeed);
        analogWrite(motorLeft1,0);
        analogWrite(motorLeft2,avgSpeed2 + gainSpeed);    
        analogWrite(motorRight1,0);
        analogWrite(motorRight2,avgSpeed2 - gainSpeed);
        // Serial.println("Speed for motors:");
        // Serial.println(avgSpeed + gainSpeed);
        // Serial.println(avgSpeed - gainSpeed);
      }

  }
    else{

    //  Serial.println("Center");
     analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,avgSpeed2);    
      analogWrite(motorRight1,0);
      analogWrite(motorRight2,avgSpeed2);
      // Serial.println(avgSpeed); 
    } 


}
void RespReverseTimerExpired() {
  armouryReversal.end();
  state = STATE_TURNCW_IN_ARMOURY;
  armouryTurnCW.begin(RespTurnCWTimerExpired,TIMER_ARMOURY_TURNCW);
}
void RespTurnCWTimerExpired() {
  // delay(5 000);
  armouryTurnCW.end();
  state = STATE_MOVE_TOWARD_SWITCH;
  armouryTowardSwitchTimer.begin(RespTowardSwitchTimerExpired,TIMER_TOWARD_SWITCH);
}
void RespTowardSwitchTimerExpired() {
  // delay(5000);
  armouryTowardSwitchTimer.end();
  delay(5000);
  state = STATE_MOVE_AWAY_SWITCH;
  
  // armouryAwaySwitchTimer.begin(RespAwaySwitchTimerExpired,TIMER_AWAY_SWITCH);
}
// void RespAwaySwitchTimerExpired() {
//   armouryAwaySwitchTimer.end();
//   state = STATE_TURNCCW_IN_ARMOURY;
//   armouryTurnCCW.begin(RespTurnCCWTimerExpired,TIMER_ARMOURY_TURNCCW);
// }
void RespAwayLineSensed() {
  //  delay(5000);
  // armouryAwaySwitchTimer.end();
      analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,30);    
      analogWrite(motorRight1,100);
      analogWrite(motorRight2,0);
  delay(1000);
  while(analogRead(centerReading)>200){
      Serial.println("turning");
      // delay(250); 
      
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,30);    
  analogWrite(motorRight1,100);
  analogWrite(motorRight2,0); 
  }
  center++;//Set the center flag to 1
  centerFind.begin(RespToCent,TIMER_CENT);
  state = STATE_MOVE_TOWARD_ARMOURY;
// ShootingPosition.begin(RespShootPositionExpired,TIMER_ARMOURY_SHOOTING_POSITION);

  // state = STATE_TURNCCW_IN_ARMOURY;
  // armouryTurnCCW.begin(RespTurnCCWTimerExpired,TIMER_ARMOURY_TURNCCW);
}

void RespTurnCCWTimerExpired() {
  armouryTurnCCW.end();
  state = STATE_MOVE_AWAY_ARMOURY;
  ShootingPosition.begin(RespShootPositionExpired,TIMER_ARMOURY_SHOOTING_POSITION);
}
void RespShootPositionExpired() {
  ShootingPosition.end();
  state = STATE_AT_CASTROCK_POS;
  // ShootingPosition.begin(RespShootPositionExpired,TIMER_ARMOURY_TURNCW);
  armouryDetected = 0; //effectively starts reading USSensor values again

}
void InitCastRock() {

Serial.println("Chinmay Get it Shooting!!!");
      analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,0);
      analogWrite(motorRight2,0);
      
      if(!shooterSwitchFlag){
        // digitalWrite(shooterSwitch,HIGH);
      }

digitalWrite(shooterSwitch,HIGH);     
delay(5000);
 state = STATE_SHOOT_CASTROCK;
 
}

void ShootingCastRock(){
    pos = 180;
    myservo.write(pos);
    Serial.println(pos);              // tell servo to go to position in variable 'pos'
    delay(300);
    pos = 90;
    myservo.write(pos);
    delay(2000);
    stopperCounter++;
    if(stopperCounter==6){
      digitalWrite(shooterSwitch,LOW);
            analogWrite(motorLeft1,00);
      analogWrite(motorLeft2,80);    
      analogWrite(motorRight1,80);
      analogWrite(motorRight2,0);
  delay(1000);
        while(analogRead(centerReading)>200){
      Serial.println("turning");
      // delay(250); 
      
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,80);    
  analogWrite(motorRight1,80);
  analogWrite(motorRight2,0); 
  }
       

      // 
           analogWrite(motorLeft1,0);
      analogWrite(motorLeft2,0);    
      analogWrite(motorRight1,0);
      analogWrite(motorRight2,0);
      stopperCounter = 0;
      armouryDetected = 0;
      centFlag = 0;
      state = STATE_MOVE_TOWARD_ARMOURY;
    }

}

void ReverseInArmoury() {
  Serial.println("Motor Reversing");
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,avgSpeed);    
  analogWrite(motorRight1,0);
  analogWrite(motorRight2,avgSpeed);

}
void TurnCWInArmoury() {
    Serial.println("Motor CWTurn");
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,avgSpeed);    
  analogWrite(motorRight1,avgSpeed);
  analogWrite(motorRight2,0); 
}

void ForwardInArmoury() {
  Serial.println("Motor to Switch");
  analogWrite(motorLeft1,avgSpeed);
  analogWrite(motorLeft2,0);    
  analogWrite(motorRight1,avgSpeed);
  analogWrite(motorRight2,0); 
}
void ReturnToLineInArmoury() {
  Serial.println("Motor Returning from switch");
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,avgSpeed-20);    
  analogWrite(motorRight1,0);
  analogWrite(motorRight2,avgSpeed-20); 
    if(analogRead(centerReading)<200){
      Serial.println("Line SENSED");
      // delay(250); 
      
  analogWrite(motorLeft1,0);
  analogWrite(motorLeft2,0);    
  analogWrite(motorRight1,0);
  analogWrite(motorRight2,0); 
  delay(2000);
    RespAwayLineSensed();
  }  
}
void TurnCCWInArmoury() {
    Serial.println("Motor CCWTurn");
  analogWrite(motorLeft1,avgSpeed);
  analogWrite(motorLeft2,0);    
  analogWrite(motorRight1,0);
  analogWrite(motorRight2,avgSpeed); 
}
bool DetectedArmoury() {
  return false;
  LimitSwitchDetected = digitalRead(limSwitch);
  // Serial.println("Limit Switch Values");
  // Serial.println(LimitSwitchDetected);
  // delay(5000);
  if(!LimitSwitchDetected){
    Serial.println("LimitSwitchDetected");
    delay(500);
    return true;}

    else { return false;}


}
