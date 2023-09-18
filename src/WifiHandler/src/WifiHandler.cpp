#include "WifiHandler.h"

const char *wifi_tag = "WifiHandler";

#define CONNECTION_TIMEOUT 3

WifiHandler::WifiHandler(const char *ssid, const char *pass) : _ssid(ssid), _pass(pass)
{
}

WifiHandler::~WifiHandler()
{
}

void WifiHandler::checkStatus()
{
    switch (WiFi.status())
    {
    case WL_NO_SSID_AVAIL:
        ESP_LOGI(wifi_tag, "WiFi SSID not found");
        break;
    case WL_CONNECT_FAILED:
        ESP_LOGE(wifi_tag, "WiFi failed - WiFi not connected! Reason: ");
        return;
        break;
    case WL_CONNECTION_LOST:
        ESP_LOGI(wifi_tag, "WiFi connection was lost");
        break;
    case WL_SCAN_COMPLETED:
        ESP_LOGI(wifi_tag, "WiFi scan is completed");
        break;
    case WL_DISCONNECTED:
        ESP_LOGW(wifi_tag, "WiFi is disconnected");
        break;
    case WL_CONNECTED:
        ESP_LOGI(wifi_tag, "Wifi connected to SSID : %s | strength : %d", WiFi.SSID().c_str(), WiFi.RSSI());
        return;
        break;
    default:
        ESP_LOGI(wifi_tag, "WiFi Status: %d", WiFi.status());
        break;
    }
}

void WifiHandler::init()
{
    ESP_LOGI(wifi_tag, "Connecting to WiFi...");
    WiFi.begin(_ssid, _pass);
    vTaskDelay(100);

    // Will try for about 10 seconds (20x 500ms)
    int tryDelay = 500;
    int numberOfTries = 0;

    // Wait for the WiFi event
    while (true)
    {
        WifiHandler::checkStatus();
        if (WiFi.status() == WL_CONNECTED) break;
        vTaskDelay(tryDelay);

        if (numberOfTries > CONNECTION_TIMEOUT)
        {
            ESP_LOGE(wifi_tag, "Failed to connect to WiFi! | num of tries : %d", numberOfTries);
            // Use disconnect function to force stop trying to connect
            WiFi.disconnect();
            break;
        }
        else
        {
            numberOfTries++;
        }
    }

    xTaskCreate(&WifiHandler::_staticTaskFunc,
                "wifi task handler",
                4096,
                this,
                1,
                &_taskHandle);
}

/*STATIC*/ void WifiHandler::_staticTaskFunc(void *pvParam)
{
    WifiHandler *wifiHandlerObj =
        reinterpret_cast<WifiHandler *>(pvParam);

    wifiHandlerObj->_taskFunc();
}

void WifiHandler::_taskFunc()
{
    ESP_LOGI(wifi_tag, "Wifi task started !");
    while (1)
    {
        if (WiFi.status() != WL_CONNECTED)
        {
            ESP_LOGW(wifi_tag, "Wifi disconnected, trying to reconnect...");
            WiFi.disconnect();
            WiFi.reconnect();
            vTaskDelay(2000);
            WifiHandler::checkStatus();
        }
        vTaskDelay(10000);
    }
    vTaskDelete(NULL);
}