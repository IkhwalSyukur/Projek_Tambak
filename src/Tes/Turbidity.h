#include <Arduino.h>
#include <Wire.h>
#include"ADS1X15.h"

ADS1115 ADS(0x48);

void setup (){
    Serial.begin(115200);
    ADS.begin();
}

void loop (){
    ADS.setGain(0); // setGain set to 1 to more precission
    int16_t nilai_turbidity = ADS.readADC(0);
    float voltage = nilai_turbidity * (3.3 / 65536.0);
    Serial.printf("Nilai Tegangan = %f\t", voltage);
}