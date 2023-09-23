#include "DS18b20.h"

DS18B20::DS18B20(uint8_t pin) : _pin(pin)
{
}

DS18B20::~DS18B20()
{
}

bool DS18B20::begin()
{
    if (!ds.search(addr))
    {
        ds.reset_search();
        isDetected = false;
        return false;
    }

    if (OneWire::crc8(addr, 7) != addr[7])
    {
        ESP_LOGE(TEMP_TAG, "CRC is ot valid...");
        return false;
    }

    if (addr[0] != 0x10 && addr[0] != 0x28)
    {
        ESP_LOGE(TEMP_TAG, "Device is not recognized...");
        return false;
    }

    ESP_LOGI(TEMP_TAG, "Device detected");
    return true;
}

float DS18B20::getValue()
{
    if (!isDetected)
    {
        return 0.0;
    }

    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1);

    for (int i = 0; i < 9; i++)
    {
        _data[i] = ds.read();
    }

    ds.reset_search();

    byte MSB = _data[1];
    byte LSB = _data[0];
    int16_t tempRead = ((MSB << 8) | LSB);

    return tempRead / 16.0f;
}

void DS18B20::measure(Temperature_t &value)
{
    value.temp = 39.00;//getValue();
}