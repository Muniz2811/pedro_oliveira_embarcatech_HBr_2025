#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "../include/adc_temp.h"

#define LED_PIN 25
#define TEMPERATURE_UNITS 'C'

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);  
    
    printf("Iniciando monitoramento de temperatura...\n");
    
    while (true) {
        uint16_t adc_val = adc_read();
        float temperature = adc_to_celsius(adc_val);
        
        printf("Valor ADC: %d, Temperatura: %.2f °C\n", adc_val, temperature);

        gpio_put(LED_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_PIN, 0);

        sleep_ms(900);
    }
    
    return 0;
}
