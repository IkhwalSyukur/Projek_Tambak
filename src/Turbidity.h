#pragma once
#include <Arduino.h>
#include <Wire.h>
#include"ADS1X15.h"

// ADS1115 ADS(0x48);

class Turbidity
{
public:
void setup (){
    Serial.begin(115200);
    ADS.begin();
}

float read_sensor(){
    ADS.setGain(0); // setGain set to 1 to more precission
    int16_t nilai_turbidity = ADS.readADC(0);
    float voltage = nilai_turbidity * (3.3 / 26470.0);
    // voltage = map(voltage,0,3.3,0,5);
    return  voltage;
    // delay(500);
}
};

Turbidity turbidity;

// void setup (){
//     turbidity.setup();
// }

// void loop (){
//     Serial.printf("Nilai Tegangan = %f\n", turbidity.read_sensor());
// }