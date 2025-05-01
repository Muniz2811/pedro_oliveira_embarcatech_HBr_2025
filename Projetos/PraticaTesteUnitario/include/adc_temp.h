#ifndef ADC_TEMP_H
#define ADC_TEMP_H

#include <stdint.h>

/**
 * @brief Converts ADC reading to temperature in Celsius
 * 
 * @param adc_val ADC reading (12-bit)
 * @return float Temperature in Celsius
 */
float adc_to_celsius(uint16_t adc_val);

#endif /* ADC_TEMP_H */
