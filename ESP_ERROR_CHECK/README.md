# ESP_ERROR_CHECK Example

This example demonstrates the usage of the `ESP_ERROR_CHECK` macro provided by the ESP-IDF framework. This macro is used to check the return values of ESP-IDF functions and automatically handle errors in a standardized way.

## Overview

In ESP-IDF, most functions return an `esp_err_t` error code. Manually checking these values can be repetitive and error-prone. The `ESP_ERROR_CHECK` macro simplifies this by:

- Logging the error
- Aborting the application (in debug builds)

This ensures that issues are caught early during development.

## How It Works

```c
ESP_ERROR_CHECK(esp_some_function());
```

If `esp_some_function()` returns anything other than `ESP_OK`, the macro will log an error message and abort the application (typically with an assertion failure).

## Example Code

```c
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"

void app_main(void)
{
    // ESP_ERROR_CHECK(x) where x is an esp_err_t type function which when executed right returns ESP_OK
    // so ESP_ERROR_CHECK(x) executes x and when completed and returned ESP_OK, the function stops

    esp_err_t func()
    {
        printf("Hello world\n");
        return ESP_OK;
    }

    while (1)
    {
        ESP_ERROR_CHECK(func());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
```

## Expected Output

```
Hello world
Hello world
Hello world
...
```

If `func()` were to return an error, you would see something like:

```
E (123) main: esp_err_t 0x105 at 0x400d1234
abort() was called at PC 0x400d5678 on core 0
```

## Notes

- `ESP_ERROR_CHECK` is especially useful during development.
- In production builds, consider replacing it with custom error handling logic.

## Requirements

- ESP-IDF installed and configured
- An ESP32 or compatible development board

## Building and Flashing

```bash
idf.py build
idf.py -p (PORT) flash
idf.py -p (PORT) monitor
```

Replace `(PORT)` with the actual serial port of your device.

## References

- [ESP-IDF Documentation - Error Handling](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/error-handling.html)
- [FreeRTOS API Reference](https://www.freertos.org/a00106.html)

---

Happy Coding! 🚀

