#pragma once

#include <Arduino.h>
#include "WifiHandler/src/WifiHandler.h"

WifiHandler wifi("eFisheryPlus", "123123123");

void setup()
{
    Serial.begin(115200);
    Serial.println("before config");
    vTaskDelay(1000);

    wifi.init();

    Serial.println("after config");
}

void loop()
{

}