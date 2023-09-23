#pragma once
#include <Arduino.h>

#include "Sensors/DOSensor.h"

#define DO_PIN_ADS 2

DOSensor DO_sensor(DO_PIN_ADS); 

DO_Value DOvalue;

void setup()
{
    Serial.begin(115200);
    delay(1000);

    DO_sensor.init();
    // DO_sensor.calibrate(0);
    DO_sensor.Measure(DOvalue);

    Serial.printf("DO value : %4.2f %\n", DOvalue.value);
}

void loop()
{
    vTaskDelete(NULL);
}