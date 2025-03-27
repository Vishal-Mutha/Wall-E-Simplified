#include "pindefs.h"

void enable_led_pins() {
    for (int i = 0; i < 8; i++) {
        // enabling the pins mentioned by setting their direction as output
        gpio_set_direction(pin_out[i], GPIO_MODE_OUTPUT);
    }
}

void all_led_high() {
    for (int i = 0; i < 8; i++) {
        gpio_set_level(pin_out[i], 1);
    }
}

void all_led_low() {
    for (int k = 0; k < 8; k++) {
        gpio_set_level(pin_out[k], 0);
    }
}

void enable_led_pins_gpio_config() {
    
    // gpio_config_t is a structure where all the gpio pin functions/variables are stored
    // we then can select and alter the gpio pins configuration as per our choice
    gpio_config_t io_conf[8];

    for (int i = 0; i < 8; i++)
    {
        io_conf[i].pin_bit_mask = (1ULL << pin_out[i]);   // pin selector
        io_conf[i].mode = GPIO_MODE_OUTPUT;               // sets the direction as output
        io_conf[i].pull_up_en = 0;                        // disables pull up resistor
        io_conf[i].pull_down_en = 1;                      // enables pull down resistor
        io_conf[i].intr_type = GPIO_INTR_DISABLE;         // disables interupt loading
        gpio_config(&io_conf[i]);                         // finally initializes the above all together
    }
}