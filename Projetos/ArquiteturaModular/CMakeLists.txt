cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w CACHE STRING "Board type" FORCE)

# Inicializa o SDK do Pico
set(PICO_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../pico-sdk")
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(atividade5 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/app/main.c
    ${CMAKE_CURRENT_LIST_DIR}/drivers/led_embutido.c
    ${CMAKE_CURRENT_LIST_DIR}/hal/hal_led.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_cyw43_arch_none 
)

pico_add_extra_outputs(${PROJECT_NAME})
