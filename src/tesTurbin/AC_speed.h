//Libraries
#pragma once
#include <Arduino.h>
#include <RBDdimmer.h>//https://github.com/RobotDynOfficial/RBDDimmer
//Parameters
const int zeroCrossPin  = 15;
const int acdPin  = 4;
int MIN_POWER  = 0;
int MAX_POWER  = 80;
int POWER_STEP  = 2;
//Variables
int power  = 0;
//Objects
dimmerLamp acd(acdPin,zeroCrossPin);

void testDimmer(){/* function testDimmer */
////Sweep light power to test dimmer
  for(power=MIN_POWER;MAX_POWER;power+=POWER_STEP){
    acd.setPower(power); // setPower(0-100%);
      Serial.print("lampValue -> ");
      Serial.print(acd.getPower());
      Serial.println("%");
    delay(500);
  }
  for(power=MAX_POWER;power>=MIN_POWER;power-=POWER_STEP){
    acd.setPower(power); // setPower(0-100%);
      Serial.print("lampValue -> ");
      Serial.print(acd.getPower());
      Serial.println("%");
    delay(500);
  }
}

void setup(){
//Init Serial USB
Serial.begin(115200);
Serial.println(F("ESP32 System"));
acd.begin(NORMAL_MODE, ON);
}
void loop(){
  testDimmer();
}
