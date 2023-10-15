#include "ServerHandler.h"

#define serverTag "SERVER"

ServerHandler::ServerHandler(const char *apSSID) : apSSID_(apSSID)
{
    server = new WebServer(80);
}

ServerHandler::~ServerHandler()
{
}

bool ServerHandler::begin()
{
    if (!WiFi.softAP(apSSID_))
    {
        ESP_LOGW(serverTag, "Failed to active AP server");
        return false;
    }
    else
    {
        // server.on("/tes", handleRoot);
        server->on("/GetData", [this]() {
            if(server)
            {
                server->send(200, "text/plain", receiveData_);
            }
        });
        server->begin();
        ESP_LOGI(serverTag, "server activated with name '%s' and IP %s", apSSID_, WiFi.softAPIP().toString().c_str());
    }

    // Create the task regardless of the connection status
    xTaskCreate(&ServerHandler::_staticTaskFunc,
                "server task handler",
                4096,
                this,
                1,
                NULL);

    return true;
}

void ServerHandler::postToClient(String &storedVar)
{
    receiveData_ = storedVar;
}

/*STATIC*/ void ServerHandler::_staticTaskFunc(void *parameter)
{
    ServerHandler *serverObj = reinterpret_cast<ServerHandler *>(parameter);
    serverObj->_taskFunc();
}

void ServerHandler::_taskFunc()
{
    ESP_LOGI(serverTag, "Server Task Started !");
    while (1)
    {
        server->handleClient();
        vTaskDelay(200);
    }
    delete server;
    vTaskDelete(NULL);
}