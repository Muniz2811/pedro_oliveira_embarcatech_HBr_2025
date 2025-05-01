# Atividade 4 - ADC para Temperatura

cmake_minimum_required(VERSION 3.13)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_FOR_PICO "Build for Raspberry Pi Pico" ON)

if(BUILD_FOR_PICO)
    set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../pico-sdk CACHE PATH "Path to the Raspberry Pi Pico SDK")
    include(pico_sdk_import.cmake)
    
    project(atividade4_pico C CXX ASM)

    pico_sdk_init()

    add_library(adc_temp src/adc_temp.c)
    target_include_directories(adc_temp PUBLIC include)

    add_executable(atividade4_pico app/main.c)

    pico_enable_stdio_uart(atividade4_pico 0)
    pico_enable_stdio_usb(atividade4_pico 1)
    
    # Adiciona as bibliotecas necessárias
    target_link_libraries(atividade4_pico
        adc_temp
        pico_stdlib
        hardware_adc
    )

    pico_add_extra_outputs(atividade4_pico)
    
else()
    # Configuração para testes locais
    project(atividade4_test C)
    
    # Inclui os diretórios necessários
    include_directories(include unity)
    
    # Adiciona a biblioteca de conversão ADC para temperatura
    add_library(adc_temp src/adc_temp.c)
    
    # Adiciona a biblioteca Unity para testes
    add_library(unity unity/unity.c)
    
    # Adiciona o executável de teste
    add_executable(test_adc_temp test/test_adc_temp.c)
    target_link_libraries(test_adc_temp adc_temp unity)
    
    # Adiciona um alvo personalizado para executar os testes
    add_custom_target(run_tests
        COMMAND test_adc_temp
        DEPENDS test_adc_temp
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()
