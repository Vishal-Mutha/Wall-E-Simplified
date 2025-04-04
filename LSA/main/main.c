#include "lsa.c"

void app_main(void)
{
    lsa_configuration();
    while(1) {
        for(int i = 0; i < 5; i++) {
            printf("%d: ", i);
                printf("%d ", lsa_read(i));
        }
        printf("\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}