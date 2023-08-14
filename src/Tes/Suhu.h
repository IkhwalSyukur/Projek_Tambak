#include <Arduino.h>
#include <OneWire.h>

float datasuhu;

class TemperatureSensor {
public:
  
  TemperatureSensor(int pin) : ds(pin) {}

  void begin() {
    
  }

  float readTemperature() {
    byte data[12];
    byte addr[8];

    if (!ds.search(addr)) {
      ds.reset_search();
      return -1000;
    }

    if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return -1000;
    }

    if (addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized");
      return -1000;
    }

    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1);

    byte present = ds.reset();
    ds.select(addr);
    ds.write(0xBE);

    for (int i = 0; i < 9; i++) {
      data[i] = ds.read();
    }

    ds.reset_search();

    byte MSB = data[1];
    byte LSB = data[0];
    int16_t tempRead = ((MSB << 8) | LSB);
    float temperatureSum = tempRead / 16.0f;

    return temperatureSum;
  }

private:
  OneWire ds;
};

TemperatureSensor tempSensor(5); // DS18S20 Signal pin on digital 5

void setup() {
  Serial.begin(115200);
  tempSensor.begin();
}

void loop() {
  float temperature = tempSensor.readTemperature();
  if (temperature > 0){
    datasuhu = temperature;
  }
  Serial.println(datasuhu);
  delay(100);
}
