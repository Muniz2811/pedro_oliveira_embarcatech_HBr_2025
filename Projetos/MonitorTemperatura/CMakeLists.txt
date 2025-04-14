# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set PICO_SDK_PATH
set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../pico-sdk)

# Initialise pico_sdk from installed location
include(pico_sdk_import.cmake)

project(temp_sensor)

# Initialize the SDK
pico_sdk_init()

# Add executable
add_executable(temp_sensor
    temp_sensor.c
    inc/ssd1306_i2c.c
)

pico_enable_stdio_uart(temp_sensor 0)
pico_enable_stdio_usb(temp_sensor 1)

# Add the standard include files to the build
target_include_directories(temp_sensor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(temp_sensor
    pico_stdlib
    hardware_i2c
    hardware_adc
)

pico_add_extra_outputs(temp_sensor)
