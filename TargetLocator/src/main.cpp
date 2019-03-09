#include <Arduino.h>
#include <AccelStepper.h>

#define TestPin 5

double firstRise=0;
double secondRise=0;
double firstFall=0;
double riseTime;
double fallTime;
double frequency;
double DC;
int checkSignal1 = 20;
int checkSignal2 = 18;
int flag = 0;

int step = 6;
int dir = 7;

void riseCounter(void);
void fallCounter(void);
void calculator(void);

AccelStepper mystepper(1, step, dir);
void runStepperSpeed(void);

void setup()
{
  Serial.begin(9600);
  pinMode(checkSignal1, INPUT);
  pinMode(checkSignal2, INPUT);
  pinMode(TestPin, OUTPUT);
  // attachInterrupt(digitalPinToInterrupt(checkSignal1), riseCounter, RISING);
  // attachInterrupt(digitalPinToInterrupt(checkSignal2), fallCounter, FALLING);
// digitalWrite(TestPin,LOW);
  mystepper.setSpeed(500);

  // put your setup code here, to run once:
}

void loop()
{
  // Serial.println(firstRise);
  // Serial.println(secondRise);
  // delay(500);
    double duration1 = pulseIn(checkSignal1, HIGH);
    double duration2 = pulseIn(checkSignal1, LOW);
    double freq = 1000000/(duration1 + duration2);
    double DC = duration1/ (duration1 + duration2);
    Serial.println("Hello");
    Serial.println(freq);
    Serial.println(DC);
    if(DC<0.55 && DC>0.47 && freq<1350 && freq>1150) {
      Serial.println("Hello");
    
      mystepper.setSpeed(0);

    }


    runStepperSpeed();
  // cli();
  // // calculator();
  // // Serial.println(frequency);

  //  Serial.println(DC);
  // sei();
  // put your main code here, to run repeatedly:
}

void riseCounter()
{
  //Serial.println("flag");
  //Serial.println(flag)
  digitalWrite(TestPin,HIGH);
  flag++;
  firstRise = micros();
  frequency = 1000000/(firstRise-secondRise);

  secondRise = firstRise; 

  // if (flag % 2 == 0)
  // {
  //   secondRise = micros();
  // }
  // else
  // {
  //   firstRise = micros();
  // }
}

void fallCounter()
{
  digitalWrite(TestPin,LOW);
  // if (flag != 0)
  // {
  //   firstFall = micros();
  // }
  firstFall = micros();
}
void calculator()
{
  DC = 100 * ((firstFall- firstRise) / (secondRise - firstRise));
  frequency = 1000000 * (1 / (secondRise - firstRise));
  // Serial.println("DC");
  // Serial.println(DC);
  // Serial.println("Freq");
  // Serial.println(frequency);
}

void runStepperSpeed()
{
  mystepper.runSpeed();
}