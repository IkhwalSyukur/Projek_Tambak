#include "Arduino.h"
#include "Adafruit_ADS1X15.h"
#include "DFRobot_ESP_EC.h"
#include "EEPROM.h"

class EC_Measurement {
private:
  DFRobot_ESP_EC ec;
  Adafruit_ADS1115 ads;

  float voltage, ecValue, temperature;

public:
  EC_Measurement() : voltage(0.0), ecValue(0.0), temperature(25.0) {}

  void setup() {
    Serial.begin(115200);
    EEPROM.begin(32);
    ec.begin();
    ads.setGain(GAIN_ONE);
    ads.begin();
  }

  void read() {
    static unsigned long timepoint = millis();
    if (millis() - timepoint > 1000U) {
      timepoint = millis();
      voltage = ads.readADC_SingleEnded(3) / 10;
    //   Serial.print("Voltage:");
    //   Serial.println(voltage, 4);

    //   // temperature = readTemperature(); // read your temperature sensor for temperature compensation
    //   Serial.print("Temperature:");
    //   Serial.print(temperature, 1);
    //   Serial.println("^C");

      ecValue = ec.readEC(voltage, temperature); // convert voltage to EC with temperature compensation
      Serial.print("EC:");
      Serial.print(ecValue, 4);
      Serial.println(" ms/cm");
    }
    ec.calibration(voltage, temperature); // calibration process through Serial CMD
  }

private:
  float readTemperature() {
    // add your code here to get the temperature from your temperature sensor
    return 25.0; // Return a default value for demonstration purposes
  }
};

EC_Measurement ecMeasurement;

// void setup() {
//   ecMeasurement.setup();
// }

// void loop() {
//   ecMeasurement.loop();
// }
