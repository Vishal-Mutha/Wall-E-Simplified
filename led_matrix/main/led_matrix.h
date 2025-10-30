#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// === Pin definitions ===
#define DATA_PIN   12
#define CLOCK_PIN  25
#define LATCH_PIN  13

// === Configuration ===
#define NUM_REGISTERS 4
#define NUM_LEDS (NUM_REGISTERS * 8)

static uint8_t shift_data[NUM_REGISTERS] = {0};

// === Letter patterns (5x6 font) ===
static const uint8_t letterS[5] = {
    0b011110,
    0b010000,
    0b011110,
    0b000010,
    0b011110
};

static const uint8_t letterR[5] = {
    0b011110,
    0b010010,
    0b011110,
    0b010100,
    0b010010
};

static const uint8_t letterA[5] = {
    0b011110,
    0b010010,
    0b011110,
    0b010010,
    0b010010
};

// === Helper Functions ===
//Initialize GPIO's attached with the shift registers
static void gpio_init();

// Send all 32 bits to the cascaded shift registers
static void update_shift_registers(void);

// Turn ON or OFF a specific LED (0–31)
static void set_led(int led_index, bool state);

// Turn OFF all LEDs
static void clear_all(void);

// Display a 5x6 pattern on the LED matrix
static void display_pattern(const uint8_t pattern[5]);
