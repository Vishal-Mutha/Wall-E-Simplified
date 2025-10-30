#include "led_matrix.c"

void app_main(void)
{
    gpio_init();
    printf("Displaying letters S, R, A on 6x5 LED Matrix\n");

    while (1) {
        display_pattern(letterS);
        printf("Displaying S\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

        display_pattern(letterR);
        printf("Displaying R\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

        display_pattern(letterA);
        printf("Displaying A\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}