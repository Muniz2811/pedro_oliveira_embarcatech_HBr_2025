#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306_i2c.h"

#define BUTTON_A 5
#define BUTTON_B 6
#define I2C_SDA 14
#define I2C_SCL 15

volatile int contador = 9;
volatile int clicks_button_b = 0;
volatile bool contagem_ativa = false;
volatile bool button_a_pressed = false;
volatile bool button_b_pressed = false;
volatile uint64_t last_button_a_time = 0;
volatile uint64_t last_button_b_time = 0;

void gpio_callback(uint gpio, uint32_t events) {
    uint64_t current_time = time_us_64();
    
    if (gpio == BUTTON_A) {
        if (current_time - last_button_a_time >= 200000) { 
            button_a_pressed = true;
            last_button_a_time = current_time;
        }
    }
    else if (gpio == BUTTON_B) {
        if (current_time - last_button_b_time >= 200000) { 
            if (contagem_ativa) {
                clicks_button_b++;
                button_b_pressed = true;
            }
            last_button_b_time = current_time;
        }
    }
}

void update_display(uint8_t *buffer) {

    memset(buffer, 0, ssd1306_width * ssd1306_n_pages);

    char str[32];
    sprintf(str, "Contador: %d", contador);
    ssd1306_draw_string(buffer, 0, 0, str);

    sprintf(str, "Clicks B: %d", clicks_button_b);
    ssd1306_draw_string(buffer, 0, 16, str);

    struct render_area area = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
    };
    
    calculate_render_area_buffer_length(&area);
    render_on_display(buffer, &area);
}

int main() {
    stdio_init_all();

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    uint8_t buffer[ssd1306_width * ssd1306_n_pages];

    absolute_time_t next_count_time = make_timeout_time_ms(1000);

    while (true) {
        if (button_a_pressed) {
            contador = 9;
            clicks_button_b = 0;
            contagem_ativa = true;
            button_a_pressed = false;
            next_count_time = make_timeout_time_ms(1000);
        }
        if (contagem_ativa && absolute_time_diff_us(get_absolute_time(), next_count_time) <= 0) {
            contador--;
            next_count_time = make_timeout_time_ms(1000);

            if (contador <= 0) {
                contador = 0;
                contagem_ativa = false;
            }
        }

        update_display(buffer);
        sleep_ms(10);
    }

    return 0;
}
