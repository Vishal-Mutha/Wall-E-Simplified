# LED Array Blink Project

This project demonstrates how to blink an array of LEDs using ESP-IDF on the SRA BOARD. The code configures multiple GPIO pins as output and alternates between turning them on and off.

## File Structure

- `main.c` - Main application file that contains the logic for blinking the LEDs.
- `led_blink.c` - Contains helper functions that configure GPIO pins and control LED behavior.
- `pindefs.h` - Header file with all the defines of gpio pins used in the led array.

## How It Works

### Initialization
1. **enable_led_pins()** - Configures the required GPIO pins as output using `gpio_set_direction()`.

2. **all_led_high()** - Sets all the configured GPIO pins to a high state (turns on all LEDs).

3. **all_led_low()** - Sets all the configured GPIO pins to a low state (turns off all LEDs).

4. **gpio_set_level(pin, level)** - Sets the output level of a GPIO pin. A value of 1 sets the pin high, while 0 sets it low.

5. **vTaskDelay(time_ms / portTICK_PERIOD_MS)** - Introduces a delay in milliseconds.

## Code Explanation

### Main Loop
- The main loop blinks all LEDs together five times, with a 1-second delay between each blink.
- After this, it iterates through all configured pins one by one, turning each on and off with a 1-second delay.

### GPIO Functions

#### gpio_set_direction
```c
esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode);
```
- **gpio_num**: Pin number to be configured.
- **mode**: Specifies whether the pin is input (`GPIO_MODE_INPUT`) or output (`GPIO_MODE_OUTPUT`).
- **Returns**: `ESP_OK` if successful, or an error code otherwise.

#### gpio_set_level
```c
esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level);
```
- **gpio_num**: Pin number to be set.
- **level**: High (1) or Low (0) to set the pin state.
- **Returns**: `ESP_OK` if successful, or an error code otherwise.

#### gpio_config_t Structure
```c
typedef struct {
    uint64_t pin_bit_mask;    // GPIO pin mask
    gpio_mode_t mode;         // GPIO mode (input/output)
    gpio_pullup_t pull_up_en; // Enable/disable internal pull-up
    gpio_pulldown_t pull_down_en; // Enable/disable internal pull-down
    gpio_intr_type_t intr_type;   // Interrupt mode
} gpio_config_t;
```
- **pin_bit_mask**: Bitmask of the GPIO pins to configure.
- **mode**: Pin mode - input, output, or open-drain.
- **pull_up_en**: Enables pull-up resistor if `GPIO_PULLUP_ENABLE` is used.
- **pull_down_en**: Enables pull-down resistor if `GPIO_PULLDOWN_ENABLE` is used.
- **intr_type**: Specifies the type of interrupt (if any) for the pin.

## Usage

1. Build and flash the code to your ESP32 using `idf.py flash`.
2. Monitor the output using `idf.py monitor` to verify that the LEDs blink correctly.

## Troubleshooting
- Check the GPIO pin configuration if LEDs do not blink.
- Verify power supply to the board and connected LEDs.