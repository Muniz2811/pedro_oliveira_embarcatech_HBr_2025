#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "inc/ssd1306_i2c.h"

#define I2C_SDA 14
#define I2C_SCL 15
#define JOYSTICK_X 26  
#define JOYSTICK_Y 27  
#define JOYSTICK_BTN 22

void update_display(uint8_t *buffer, uint16_t x_value, uint16_t y_value, bool button_pressed) {

    memset(buffer, 0, ssd1306_width * ssd1306_n_pages);
    
    char str[32];

    sprintf(str, "X: %d", x_value);
    ssd1306_draw_string(buffer, 0, 0, str);
    
    sprintf(str, "Y: %d", y_value);
    ssd1306_draw_string(buffer, 0, 16, str);

    sprintf(str, "BTN: %s", button_pressed ? "PRESSED" : "RELEASED");
    ssd1306_draw_string(buffer, 0, 32, str);

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

    adc_init();

    adc_gpio_init(JOYSTICK_X);
    adc_gpio_init(JOYSTICK_Y);

    gpio_init(JOYSTICK_BTN);
    gpio_set_dir(JOYSTICK_BTN, GPIO_IN);
    gpio_pull_up(JOYSTICK_BTN);

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    uint8_t buffer[ssd1306_width * ssd1306_n_pages];

    while (true) {
        adc_select_input(0);  
        uint16_t x_raw = adc_read();

        adc_select_input(1);  
        uint16_t y_raw = adc_read();

        bool button_pressed = !gpio_get(JOYSTICK_BTN);

        update_display(buffer, x_raw, y_raw, button_pressed);

        sleep_ms(50);
    }

    return 0;
}
