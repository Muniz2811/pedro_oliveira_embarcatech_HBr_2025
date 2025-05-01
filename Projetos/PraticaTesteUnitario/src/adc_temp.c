#include "../include/adc_temp.h"

/**
 * @brief Converts ADC reading to temperature in Celsius
 * 
 * Formula: T = 27 - ((ADC_VAL x 3.3/4095)-0.706)/0.001721
 * 
 * @param adc_val ADC reading (12-bit)
 * @return float Temperature in Celsius
 */
float adc_to_celsius(uint16_t adc_val) {
    float voltage = (float)adc_val * 3.3f / 4095.0f;
    float temperature = 27.0f - ((voltage - 0.706f) / 0.001721f);
    return temperature;
}
