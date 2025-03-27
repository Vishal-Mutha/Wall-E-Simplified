#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN_1 GPIO_NUM_12
#define LED_PIN_2 GPIO_NUM_13  
#define LED_PIN_3 GPIO_NUM_25
#define LED_PIN_4 GPIO_NUM_26
#define LED_PIN_5 GPIO_NUM_15  
#define LED_PIN_6 GPIO_NUM_5
#define LED_PIN_7 GPIO_NUM_18
#define LED_PIN_8 GPIO_NUM_19

int pin_out[8] = {LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4, LED_PIN_5, LED_PIN_6, LED_PIN_7, LED_PIN_8};