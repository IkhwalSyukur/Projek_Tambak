#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <WebServer.h>
#include <ThingsBoard.h>

const char* wifiSSID = "Variasi Aluminium 1";
const char* wifiPassword = "hapisahsyukur2";

const char* apSSID = "ESP-SoftAP";
const char* apPassword = "";

const char* thingsboardToken = "Ojz6j6cfFJgIJmz1ZIyh";
const char* thingsboardServer = "thingsboard.cloud";
const uint16_t thingsboardPort = 1883;

WebServer server(80);
WiFiClient client;
ThingsBoard tb(client);

String receivedData;

void handleRoot() {
  server.send(200, "text/plain", "Hello from ESP32 A!");
}

void handleGetData() {
  server.send(200, "text/plain", receivedData);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(wifiSSID, wifiPassword);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");

  // Connect to ThingsBoard server
  Serial.print("Connecting to ThingsBoard...");
  if (!tb.connect(thingsboardServer, thingsboardToken, thingsboardPort)) {
    Serial.println("Failed to connect to ThingsBoard!");
  } else {
    Serial.println("Connected to ThingsBoard!");
  }


  // Start the server
WiFi.softAP(apSSID);
  Serial.print("Soft AP SSID: ");
  Serial.println(apSSID);
  Serial.print("Soft AP IP Address: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", handleRoot);
  server.on("/GetData", handleGetData);
  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
  // Handle incoming client connections
  server.handleClient();

  // Send data to ESP32 "B"
  // ...

  // Example: sending random data to ESP32 "B" every 5 seconds
  receivedData = "Data from ESP32 A: " + String(random(0, 100));

  // Send data to ThingsBoard
  // ...

  // Example: sending random data to ThingsBoard every 10 seconds
  tb.sendTelemetryInt("random_data", random(0, 100));
  delay(10000);
}
