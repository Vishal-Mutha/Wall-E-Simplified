# Line Sensor Array (LSA) Example

This repository demonstrates how to read analog values from a 5-sensor IR line sensor array using the ESP-IDF framework.

## Overview

The Line Sensor Array (LSA) consists of five infrared (IR) sensors that provide analog readings based on reflectivity. These readings can be used for applications such as line following robots.

## Components Used

- ESP32 Development Board
- 5-Channel IR Line Sensor Array

## How It Works

1. **Configuration:** The ADC channels for the IR sensors are configured.
2. **Reading Values:** The ESP32 reads analog values from all 5 sensors in a loop.
3. **Output:** The values are printed to the serial monitor.

## Example Code

### `main.c`
```c
#include "lsa.c"

void app_main(void)
{
    lsa_configuration();
    while(1) {
        for(int i = 0; i < 5; i++) {
            printf("%d: %d ", i, lsa_read(i));
        }
        printf("\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
```

### `lsa.c`
```c
#include "pindefs.h"

void lsa_configuration() {
    for(int i = 0; i < 5; i++) {
        adc1_config_channel_atten(LSA_PINS[i], ADC_ATTEN_DB_11);
    }
    adc1_config_width(ADC_BITWIDTH_12);
}

int lsa_read(int i) {
    return adc1_get_raw(LSA_PINS[i]);
}
```

### `pindefs.h`
```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

#define LSA_PIN_0 ADC1_CHANNEL_0
#define LSA_PIN_1 ADC1_CHANNEL_3
#define LSA_PIN_2 ADC1_CHANNEL_6
#define LSA_PIN_3 ADC1_CHANNEL_7
#define LSA_PIN_4 ADC1_CHANNEL_4

int LSA_PINS[5] = {LSA_PIN_0, LSA_PIN_1, LSA_PIN_2, LSA_PIN_3, LSA_PIN_4};
```

## Expected Output

The ESP32 will print the sensor readings continuously:
```
0: 1234 1: 1100 2: 980 3: 1400 4: 1200
0: 1250 1: 1120 2: 990 3: 1380 4: 1225
...
```

## Requirements

- ESP-IDF installed and configured
- An ESP32 board
- IR Line Sensor Array

## Building and Flashing

```bash
idf.py build
idf.py -p (PORT) flash
idf.py -p (PORT) monitor
```

Replace `(PORT)` with the actual serial port of your device.

## Notes

- The sensors return different values based on the surface reflectivity.
- Higher values indicate more reflectivity (lighter surfaces), and lower values indicate less reflectivity (darker surfaces).

---

Happy Coding! 🚀

