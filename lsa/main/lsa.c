#include "pindefs.h"

void lsa_configuration() {
    for(int i = 0; i < 5; i++) {
    adc1_config_channel_atten(LSA_PINS[i], ADC_ATTEN_DB_11);
    }
    adc1_config_width(ADC_BITWIDTH_12);
}

int lsa_read(int i) {
    for(int i = 0; i < 5; i++) {
        lsa_readings[i] = adc1_get_raw(LSA_PINS[i]);
    }
    return lsa_readings[i];
}