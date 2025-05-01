/**
 * @file led_embutido.c
 * @brief Implementação do driver para o LED embutido da Raspberry Pi Pico W
 */

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "../include/led_embutido.h"

bool led_embutido_init(void) {
    stdio_init_all();
    return (cyw43_arch_init() == 0);
}

void led_embutido_set(bool estado) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, estado ? 1 : 0);
}

bool led_embutido_get(void) {
    return cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN);
}
