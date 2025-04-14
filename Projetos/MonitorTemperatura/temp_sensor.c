#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "inc/ssd1306_i2c.h"

#define I2C_SDA 14
#define I2C_SCL 15

#define CONVERSION_FACTOR (3.3f / (1 << 12))  
#define TEMP_SENSOR 4                        

float convert_to_celsius(uint16_t raw) {
    float voltage = raw * CONVERSION_FACTOR;
    float temp_c = 27.0f - (voltage - 0.706f) / 0.001721f;
    
    return temp_c;
}


void update_display(uint8_t *buffer, float temp) {

    memset(buffer, 0, ssd1306_width * ssd1306_n_pages);

    char str[32];

    ssd1306_draw_string(buffer, 0, 0, "Temperatura RP2040");

    sprintf(str, "%.2f C", temp);
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

    adc_init();

    adc_set_temp_sensor_enabled(true);
    adc_select_input(TEMP_SENSOR);

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    uint8_t buffer[ssd1306_width * ssd1306_n_pages];

    while (true) {
        uint16_t raw = adc_read();

        float temp = convert_to_celsius(raw);

        update_display(buffer, temp);

        sleep_ms(500); 
    }

    return 0;
}
