#pragma once
#include <Arduino.h>
#include "DFRobot_ESP_PH_WITH_ADC.h"
#include "OneWire.h"
#include "DallasTemperature.h"
#include "Adafruit_ADS1X15.h"
#include "EEPROM.h"

class PH_Measurement {
private:
  DFRobot_ESP_PH_WITH_ADC ph;
  Adafruit_ADS1115 ads;
  OneWire oneWire;
  DallasTemperature sensors;

  float voltage, phValue, temperature;

public:
  PH_Measurement() : voltage(0.0), phValue(0.0), temperature(25.0), oneWire(15), sensors(&oneWire) {}

  void setup() {
    Serial.begin(115200);
    EEPROM.begin(32);
    ph.begin();
    sensors.begin();
    ads.setGain(GAIN_ONE);
    ads.begin();
  }

  float calculatePH() {
    return phValue = ph.readPH(voltage, temperature);
    // Serial.print("pH:");
    // Serial.println(phValue, 4);
  }

  float read() {
    static unsigned long timepoint = millis();
    if (millis() - timepoint > 1000U) {
      timepoint = millis();
      readVoltage();
      readTemperature();
      calculatePH();
    }
    calibratePH();
    return calculatePH();
  }

private:
  void readVoltage() {
    voltage = ads.readADC_SingleEnded(1) / 10;
    // Serial.print("Voltage:");
    // Serial.println(voltage, 4);
  }

  int readTemperature() {
    sensors.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);
    return temperature;
    // Serial.print("Temperature:");
    // Serial.print(temperature, 1);
    // Serial.println("^C");
  }

  void calibratePH() {
    ph.calibration(voltage, temperature);
  }
};

PH_Measurement phMeasurement;

// void setup() {
//   phMeasurement.setup();
// }

// void loop() {
//   phMeasurement.loop();
// }
