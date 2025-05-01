#include "../include/adc_temp.h"
#include "../unity/unity.h"
#include <stdio.h>

void setUp(void) {
    // set up code if needed
}

void tearDown(void) {
    // clean up code if needed
}

/**
 * @brief Test the ADC to Celsius conversion function
 * 
 * For a voltage of 0.706V (which corresponds to an ADC value of 
 * 0.706 * 4095 / 3.3 = 875.5 ≈ 876), the temperature should be 27°C
 */
void test_adc_to_celsius(void) {
    uint16_t adc_val = 876;
    float expected_temp = 27.0f;
    float actual_temp = adc_to_celsius(adc_val);
    TEST_ASSERT_FLOAT_WITHIN(0.1f, expected_temp, actual_temp);
    
    printf("ADC value: %d, Temperature: %.2f°C\n", adc_val, actual_temp);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_adc_to_celsius);
    return UNITY_END();
}
