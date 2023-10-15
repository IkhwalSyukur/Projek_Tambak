#include "DOSensor.h"

DOSensor::DOSensor(uint8_t pin) : _pin(pin), adcRaw(0), adcVoltage(0)
{
    ADS = new ADS1115(0x48);
}

DOSensor::~DOSensor()
{
    delete ADS;
}

bool DOSensor::init()
{
    if (!ADS->begin())
    {
        ESP_LOGE(DO_SENSOR_TAG, "DO sensor failed to run. ADS1115 not detected");
        _state = false;
        return false;
    }
    else
    {
        _state = true;
        _temp = DEFAULT_TEMP;
        ESP_LOGI(DO_SENSOR_TAG, "DO sensor ready !");
    }

    return true;
}

bool DOSensor::calibrate(uint8_t gain)
{
    ESP_LOGI(DO_SENSOR_TAG, "Start to calibrating DO sensor...");
    _gain = gain;
    float _value = readValue();
    ESP_LOGI(DO_SENSOR_TAG, "Put the probe to 0 % buffer solution !");

    uint8_t listGain[6] = {0, 1, 2, 4, 8, 16};
    static int count = 0;

    while (_value >= 0.5)
    {
        for (uint8_t gain_ : listGain)
        {
            _gain = listGain[gain_];
            ESP_LOGI(DO_SENSOR_TAG, " DO value %4.2f | Gain = %d | Please wait...", _value, _gain);
            delay(1000);
            count++;

            if (count > 6)
            {
                ESP_LOGW(DO_SENSOR_TAG, "DO sensor can not be calibrated due to probe issue...");
                return false;
            }
        }
    }

    ESP_LOGI(DO_SENSOR_TAG, "DO sensor calibrated");
    return true;
}

bool DOSensor::Measure(DO_Value &value)
{
    value.value = 2.3;//readValue();

    if (value.value < 0)
    {
        ESP_LOGW(DO_SENSOR_TAG, "DO Sensor no longer to be used !");
        return false;
    }

    return true;
}

bool DOSensor::Measure(DO_Value &value, Temperature_t &tempVal)
{
    _temp = tempVal.temp;
    value.value = 2.45;//readValue();

    if (value.value < 0)
    {
        ESP_LOGW(DO_SENSOR_TAG, "DO Sensor no longer to be used !");
        return false;
    }

    return true;
}

int16_t DOSensor::calcValue()
{
#if TWO_POINT_CALIBRATION == 0
    uint16_t V_saturation = CAL1_V * 35 * _temp - CAL1_T * 35;
    return (adcVoltage * DO_Table[_temp] / V_saturation);
#else
    uint16_t V_saturation = (_temp - CAL2_T) * (CAL1_V - CAL2_V) / (CAL1_T - CAL2_T) + CAL2_V;
    return (adcVoltage * DO_Table[_temp] / V_saturation);
#endif
}

float DOSensor::readValue()
{
    if (_state)
    {
        ADS->setGain(_gain);
        adcRaw = ADS->readADC(_pin);
        adcVoltage = uint32_t(VREF) * adcRaw / ADC_RES;
    }

    return static_cast<float>(calcValue());
}