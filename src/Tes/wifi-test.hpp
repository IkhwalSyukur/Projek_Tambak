#pragma once

#include <Arduino.h>
#include <WifiHandler.h>

WifiHandler wifi("eFisheryPlus", "123123123");

void setup()
{
    Serial.begin(115200);
    wifi.init();
}

void loop()
{

}