#pragma once

#include "Adc.hpp"

class TemperatureSensor
{
public:
    TemperatureSensor(Adc adc);
    float GetTemperature();

private:
    const float T_NORMAL = 25;
    const float R_NORMAL = 10e3;
    const float R_REFERENCE = 10e3;
    Adc adc_;
};