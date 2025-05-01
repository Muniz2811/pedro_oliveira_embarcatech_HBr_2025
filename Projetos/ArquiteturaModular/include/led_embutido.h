/**
 * @file led_embutido.h
 * @brief Driver para controle do LED embutido da Raspberry Pi Pico W
 */

#ifndef LED_EMBUTIDO_H
#define LED_EMBUTIDO_H

#include <stdbool.h>

/**
 * @brief Inicializa o driver do LED embutido
 * 
 * @return true se a inicialização foi bem-sucedida, false caso contrário
 */
bool led_embutido_init(void);

/**
 * @brief Define o estado do LED embutido
 * 
 * @param estado true para ligar o LED, false para desligar
 */
void led_embutido_set(bool estado);

/**
 * @brief Obtém o estado atual do LED embutido
 * 
 * @return true se o LED estiver ligado, false se estiver desligado
 */
bool led_embutido_get(void);

#endif /* LED_EMBUTIDO_H */
