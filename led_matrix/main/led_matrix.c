
#include "led_matrix.h"

static void gpio_init() 
{
    gpio_reset_pin(DATA_PIN);
    gpio_reset_pin(CLOCK_PIN);
    gpio_reset_pin(LATCH_PIN);

    gpio_set_direction(DATA_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(CLOCK_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(LATCH_PIN, GPIO_MODE_OUTPUT);

}

static void update_shift_registers(void)
{
    gpio_set_level(LATCH_PIN, 0);
    for (int i = NUM_REGISTERS - 1; i >= 0; i--) {
        uint8_t data = shift_data[i];
        for (int bit = 0; bit < 8; bit++) {
            gpio_set_level(CLOCK_PIN, 0);
            gpio_set_level(DATA_PIN, (data >> bit) & 0x01);
            gpio_set_level(CLOCK_PIN, 1);
        }
    }
    gpio_set_level(LATCH_PIN, 1);
}

static void set_led(int led_index, bool state)
{
    if (led_index < 0 || led_index >= NUM_LEDS) return;

    int reg_index = led_index / 8;
    int bit_index = led_index % 8;

    if (state)
        shift_data[reg_index] |= (1 << bit_index);
    else
        shift_data[reg_index] &= ~(1 << bit_index);
}

static void clear_all(void)
{
    for (int i = 0; i < NUM_REGISTERS; i++) shift_data[i] = 0;
    update_shift_registers();
}

static void display_pattern(const uint8_t pattern[5])
{
    clear_all();

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 6; col++) {
            int physicalRow = 4 - row;   // flip vertically
            int physicalCol = col;   // flip horizontally
            int ledIndex = physicalRow * 6 + physicalCol;

            bool state = (pattern[row] >> col) & 0x01;
            set_led(ledIndex + 2, state);  // +2 offset for wiring
        }
    }

    update_shift_registers();
}