#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(Adc adc) : adc_{adc}
{
}

float TemperatureSensor::GetTemperature()
{
    float voltageNtc = adc_.Read();
    float resistanceMeasured = voltageNtc * R_REFERENCE / (adc_.GetReferenceVoltage() - voltageNtc);
    return R_NORMAL * T_NORMAL / resistanceMeasured;
}
