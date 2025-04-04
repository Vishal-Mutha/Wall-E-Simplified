#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_attr.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"

#define MOTOR_PIN_0A 4
#define MOTOR_PIN_0B 0

#define MOTOR_PIN_1A 15
#define MOTOR_PIN_1B 8