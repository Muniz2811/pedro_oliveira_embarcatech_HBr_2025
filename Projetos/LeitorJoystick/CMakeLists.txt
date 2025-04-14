# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set PICO_SDK_PATH
set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../pico-sdk)

# Initialise pico_sdk from installed location
include(pico_sdk_import.cmake)

project(joystick_oled)

# Initialize the SDK
pico_sdk_init()

# Add executable
add_executable(joystick_oled
    joystick_oled.c
    inc/ssd1306_i2c.c
)

pico_enable_stdio_uart(joystick_oled 0)
pico_enable_stdio_usb(joystick_oled 1)

# Add the standard include files to the build
target_include_directories(joystick_oled PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(joystick_oled
    pico_stdlib
    hardware_i2c
    hardware_adc
)

pico_add_extra_outputs(joystick_oled)
