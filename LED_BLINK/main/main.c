#include <stdio.h>
#include "led_blink.c"

void app_main(void)
{
    // look for this function in led_blink.c 
    // enable_led_pins_gpio_config();
    
    // enables the pins we are using and setting them for output
    enable_led_pins();           //all these fucntions are written in led_blink.c
    
    for (int i = 0; i < 5; i++)
    {
        // a function that sets all the led pins to high
        all_led_high();                              
        
        // delay of 1 sec
        // it will take a 1 sec pause after the previous line of code and then it will execute the next line of code
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        
        // a function that sets all the led pins to low       
        all_led_low();
        vTaskDelay(1000 / portTICK_PERIOD_MS);       
    }
    
    while(1) 
    {
        for (int i = 0; i < 8; i++)
        {
            // a function that sets the mentioned pin high when 1
            gpio_set_level(pin_out[i], 1);

            vTaskDelay(1000 / portTICK_PERIOD_MS);
            
            // a function that sets the mentined pin low when 0
            gpio_set_level(pin_out[i], 0);           
        }
    }
}