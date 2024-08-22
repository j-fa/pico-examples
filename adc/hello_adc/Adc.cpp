#include "Adc.hpp"
// #include "hardware/gpio.h"
#include "hardware/adc.h"

Adc::Adc(int channel, float referenceVoltage) : N_BITS{12}, channel_{channel}, referenceVoltage_{referenceVoltage}
{
    adc_init();
    adc_gpio_init(gpioFromChannel_[channel_]);
}

float Adc::Read()
{
    adc_select_input(channel_);
    return adc_read() * referenceVoltage_ / (1U << N_BITS);
}

float Adc::GetReferenceVoltage()
{
    return referenceVoltage_;
}
