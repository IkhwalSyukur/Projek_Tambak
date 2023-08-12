#include <Arduino.h>
#include "DO.h"
#include "Turbidity.h"
#include "EC.h"
#include "pH.h"

void DO_task(void *pvParameters);
void turbidity_task(void *pvParameters);
void EC_task(void *pvParameters);
void pH_task(void *pvParameters);

void setup(){
    sensor.setup();
    turbidity.setup();
    ecMeasurement.setup();
    phMeasurement.setup();

    xTaskCreatePinnedToCore(DO_task, "DO task", 1024 * 2 , NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(turbidity_task, "Turbidity task", 1024 * 2 , NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(EC_task, "EC task", 1024 * 2 , NULL, 5, NULL, 1);
    xTaskCreatePinnedToCore(pH_task, "pH task", 1024 * 2 , NULL, 5, NULL, 1);
}

void loop(){
    vTaskDelete(NULL);
}

void DO_task(void *pvParameters){
  (void) pvParameters;
  while (1) {
    sensor.readDO();
    vTaskDelay(500);
  }
}

void turbidity_task(void *pvParameters){
(void) pvParameters;
  while (1) {
    Serial.printf("Nilai Tegangan Turbidity = %f\n", turbidity.read_sensor());
    vTaskDelay(500);
  }
}

void EC_task(void *pvParameters){
  (void) pvParameters;
  while (1) {
    ecMeasurement.read();
    vTaskDelay(500);
  }
}

void pH_task(void *pvParameters){
  (void) pvParameters;
  while (1) {
    phMeasurement.read();
    vTaskDelay(500);
  }
}
