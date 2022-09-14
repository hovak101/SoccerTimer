#include "SR04.h"
#include "StopWatch.h"
#include "SevSeg.h"
#define TRIG_PIN A0
#define ECHO_PIN A1

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
SevSeg sevseg; 
StopWatch mySW; 
long a;
int elapsedTime; 
int decimalsBack; 
int buttonAPin = A2; 
int buttonBPin = B2; 

void setup() {
  //7seg screen
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);

  //ultra sonic sensor
  Serial.begin(9600);//Initialization of Serial Port
  a = sr04.Distance(); 

  //choosing number of laps
  pinMode(buttonAPin, INPUT_PULLUP); 
  pinMode(buttonBPin, INPUT_PULLUP);

  while(buttonBPin == LOW) { 
    if (digitalRead(buttonApin) == LOW){
    Serial.println("pushed");
    delay(500); 
    }
  }
  
  while(a < 61) { //61 cm is approximately 3 feet 
    a = sr04.Distance(); 
    //delay(100); 
  }
  mySW.start(); 
  delay(3000); 
  
  while (a > 61) {
    a = sr04.Distance(); 
    //delay(100); 
  }
  mySW.stop(); 
  Serial.print(mySW.elapsed()); 
  Serial.println("ms"); 

  if(mySW.elapsed()/10000 < 1) {
    elapsedTime = mySW.elapsed(); 
    decimalsBack = 3; 
  }
  else if(mySW.elapsed()/100000 < 1) {
    elapsedTime = mySW.elapsed()/10; 
    decimalsBack = 2; 
  }
  else if(mySW.elapsed()/1000000 < 1) {
    elapsedTime = mySW.elapsed()/100; 
    decimalsBack = 1; 
  }
  else if(mySW.elapsed()/10000000 < 1) {
    elapsedTime = mySW.elapsed()/1000; 
    decimalsBack = 0; 
  }
  else { 
    //throw some error; 
  }

  //Serial.println("Elapsed Time: " + elapsedTime); 
}

void loop() {
   sevseg.setNumber(elapsedTime, decimalsBack);
   sevseg.refreshDisplay(); 
}
