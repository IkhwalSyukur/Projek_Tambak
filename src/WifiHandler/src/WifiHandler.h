#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

class WifiHandler
{
private:
    /* data */
    const char* _ssid;
    const char* _pass;
public:
    WifiHandler(const char* ssid, const char* pass);
    ~WifiHandler();

    bool init();
};
