#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#define LSA_PIN_0 ADC1_CHANNEL_0    //GPIO 36
#define LSA_PIN_1 ADC1_CHANNEL_3    //GPIO 39
#define LSA_PIN_2 ADC1_CHANNEL_6    //GPIO 34      you can get all the adc number and channel number
#define LSA_PIN_3 ADC1_CHANNEL_7    //GPIO 35      from google just search "esp32 wroom 32 pinout"
#define LSA_PIN_4 ADC1_CHANNEL_4    //GPIO 32

int LSA_PINS[5] = {LSA_PIN_0, LSA_PIN_1, LSA_PIN_2, LSA_PIN_3, LSA_PIN_4};
int lsa_readings[5];