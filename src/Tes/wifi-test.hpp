#pragma once

#include <Arduino.h>
#include <WifiHandler.h>

#include "ServerHandler.h"

WifiHandler wifi("eFisheryPlus", "123123123");
ServerHandler myServer("myServer");

void setup()
{
    Serial.begin(115200);
    wifi.init();
    myServer.begin();
}

void loop()
{

}