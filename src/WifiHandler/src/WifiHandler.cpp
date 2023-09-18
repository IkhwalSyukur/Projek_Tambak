#include "WifiHandler.h"

const char *wifi_tag = "WifiHandler";

WifiHandler::WifiHandler(const char *ssid, const char *pass) : _ssid(ssid), _pass(pass)
{
}

WifiHandler::~WifiHandler()
{
}

bool WifiHandler::init()
{
    ESP_LOGI(wifi_tag, "Connecting to AP...");
    WiFi.begin(_ssid, _pass);
    vTaskDelay(100);
    size_t wl_count;
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(500);
        printf(".");
        // WiFi.reconnect();
        wl_count++;
        if (wl_count > 3)
        {
            ESP_LOGI(wifi_tag, "Wifi not connected to any AP");
            return false;
            break;
        }
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        ESP_LOGI(wifi_tag, "Wifi connected to %s", WiFi.SSID().c_str());
        return true;
    }
    // return true;
}