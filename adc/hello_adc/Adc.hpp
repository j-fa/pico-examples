#pragma once

#include <stdint.h>
#include <map>

class Adc
{
public:
    Adc(int channel, float referenceVoltage);
    float Read();
    float GetReferenceVoltage();

private:
    const int N_BITS;
    uint16_t channel_;
    float referenceVoltage_;
    std::map<int, int> gpioFromChannel_ = {
        {0, 26},
        {1, 27},
        {2, 28},
        {3, 29}};
};