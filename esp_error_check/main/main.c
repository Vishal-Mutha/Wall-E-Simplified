#include <stdio.h>
#include "freertos/FreeRTOS.h"

void app_main(void)
{
    // ESP_ERROR_CHECK(x) where x is an esp_err_t type function which when executed right returns ESP_OK
    // so ESP_ERROR_CHECK(x) executes x and when completed and returned ESP_OK, the function stops

    esp_err_t func()
    {
        printf("Hello world");
        return ESP_OK;
    }

    while (1)
    {
        ESP_ERROR_CHECK(func());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}