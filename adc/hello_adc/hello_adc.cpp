/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
// #include "hardware/gpio.h"
#include "hardware/adc.h"
#include "Adc.hpp"
#include "TemperatureSensor.hpp"

int main()
{
    stdio_init_all();

    Adc adc = Adc(0, 3.3f);
    TemperatureSensor temperatureSensor{adc};

    while (1)
    {
        float temperature_C = temperatureSensor.GetTemperature();

        // printf("R_NTC = %f Ohm\n", R_ntc);
        printf("Temperature: %f deg C\n", temperature_C);
        sleep_ms(500);
    }
}
