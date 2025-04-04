# ESP-IDF PWM Motor Control Example

This repository demonstrates how to control a motor using PWM (Pulse Width Modulation) with the ESP-IDF framework.

## Overview

The ESP32's MCPWM (Motor Control Pulse Width Modulation) module is used to generate PWM signals that control the speed and direction of a motor.

## Components Used

- ESP32 Development Board
- Motor Driver
- DC Motor

## How It Works

1. **GPIO Initialization:** The PWM control pins for the motor are assigned and initialized.
2. **PWM Configuration:** The MCPWM module is set up with a frequency of 1000Hz and a duty cycle of 0% initially.
3. **Motor Control:** Functions are implemented to control the motor's speed and direction by adjusting the PWM duty cycle.

## Example Code

### `main.c`
```c
#include <stdio.h>
#include "pwm.c"

void app_main(void)
{
    initialize_pwm_gpio_pins();
    pwm_gpio_configuration();

    while (1)
    {
        for (float i = 10.0; i < 80.0; i += 5.0)
        {
            pwm_motor_forward(i);
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }
        for (float i = 10.0; i < 80.0; i += 5.0)
        {
            pwm_motor_backward(i);
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }
    }
}
```

## Explanation of Key Functions

### `initialize_pwm_gpio_pins()`
This function initializes the GPIO pins used for PWM control by configuring them with `mcpwm_gpio_init()`.

### `pwm_gpio_configuration()` 
This function sets up the PWM parameters, including:
- **Frequency:** 1000Hz
- **Duty Cycle:** Initially set to 0%
- **Counter Mode:** MCPWM_UP_COUNTER
- **Duty Mode:** MCPWM_DUTY_MODE_0

### `pwm_motor_forward(float duty_cycle)` in pwm.c
This function sets the PWM signals to move the motor forward:
- `mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);` → Ensures one side of the H-Bridge is low.
- `mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, duty_cycle);` → Sets the duty cycle for the motor speed.
- `mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);` → Specifies the duty mode.

### `pwm_motor_backward(float duty_cycle)`
This function sets the PWM signals to move the motor backward by applying the duty cycle to the opposite outputs.

## Expected Output

The motor speed will gradually increase forward from 10% to 80% duty cycle, then reverse with the same pattern:
```
Motor moving forward at 10% duty cycle
Motor moving forward at 15% duty cycle
...
Motor moving forward at 75% duty cycle
Motor moving backward at 10% duty cycle
Motor moving backward at 15% duty cycle
...
Motor moving backward at 75% duty cycle
```

## Requirements

- ESP-IDF installed and configured
- ESP32 board
- Motor Driver
- DC Motor

## Building and Flashing

```bash
idf.py build
idf.py -p (PORT) flash
idf.py -p (PORT) monitor
```

Replace `(PORT)` with the actual serial port of your device.

## Notes

- The motor speed is controlled by adjusting the PWM duty cycle.
- The loop continuously increases and decreases the duty cycle to vary the speed.

---

Happy Coding! 🚀

