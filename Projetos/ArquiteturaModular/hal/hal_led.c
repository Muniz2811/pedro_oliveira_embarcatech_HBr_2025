/**
 * @file hal_led.c
 * @brief Implementação da camada de abstração de hardware para LEDs
 */

#include "../include/hal_led.h"
#include "../include/led_embutido.h"

bool hal_led_init(void) {
    return led_embutido_init();
}

void hal_led_set(bool estado) {
    led_embutido_set(estado);
}

bool hal_led_get(void) {
    return led_embutido_get();
}

void hal_led_toggle(void) {
    bool estado_atual = hal_led_get();
    hal_led_set(!estado_atual);
}
