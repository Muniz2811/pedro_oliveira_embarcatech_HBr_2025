/**
 * @file hal_led.h
 * @brief Camada de abstração de hardware para controle de LEDs
 */

#ifndef HAL_LED_H
#define HAL_LED_H

#include <stdbool.h>

/**
 * @brief Inicializa o subsistema de LEDs
 * 
 * @return true se a inicialização foi bem-sucedida, false caso contrário
 */
bool hal_led_init(void);

/**
 * @brief Define o estado do LED
 * 
 * @param estado true para ligar o LED, false para desligar
 */
void hal_led_set(bool estado);

/**
 * @brief Obtém o estado atual do LED
 * 
 * @return true se o LED estiver ligado, false se estiver desligado
 */
bool hal_led_get(void);

/**
 * @brief Alterna o estado do LED (liga se estiver desligado, desliga se estiver ligado)
 */
void hal_led_toggle(void);

#endif /* HAL_LED_H */
