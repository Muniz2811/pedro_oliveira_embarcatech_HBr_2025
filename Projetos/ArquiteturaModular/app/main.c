/**
 * @file main.c
 * @brief Aplicação principal que faz o LED embutido piscar
 */

#include "pico/stdlib.h"
#include "../include/hal_led.h"

int main() {
    if (!hal_led_init()) {
        return -1;
    }

    while (true) {
        hal_led_set(true);  
        sleep_ms(500);       
        hal_led_set(false);  
        sleep_ms(500);       
        
    }
}
