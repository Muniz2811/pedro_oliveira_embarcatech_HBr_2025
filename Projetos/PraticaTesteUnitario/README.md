# Atividade 4 - Conversão de ADC para Temperatura

Este projeto implementa uma função para converter leituras do ADC interno da Raspberry Pi Pico W para temperatura em graus Celsius. O projeto pode ser compilado tanto para executar testes unitários locais quanto para ser carregado na placa BitDogLab (Raspberry Pi Pico).

## Fórmula de Conversão

A conversão utiliza a fórmula da documentação oficial:

```
T = 27 - ((ADC_VAL x 3.3/4095)-0.706)/0.001721
```

Onde:
- `T` é a temperatura em graus Celsius
- `ADC_VAL` é o valor lido do ADC (12 bits)
- `3.3` é a tensão de referência (Vref) em volts
- `4095` é o valor máximo do ADC de 12 bits (2^12 - 1)

## Estrutura do Projeto

- `include/adc_temp.h`: Declaração da função de conversão
- `src/adc_temp.c`: Implementação da função de conversão
- `app/main.c`: Aplicativo principal para a BitDogLab
- `test/test_adc_temp.c`: Teste unitário usando Unity
- `unity/`: Framework Unity para testes unitários
- `CMakeLists.txt`: Configuração do CMake para compilação
- `pico_sdk_import.cmake`: Script para importar o SDK do Raspberry Pi Pico

## Compilação e Execução

### Para Testes Locais

```bash
# Crie um diretório de build para testes
mkdir -p build
cd build

# Configure o CMake para testes locais
cmake .. -DBUILD_FOR_PICO=OFF

# Compile o projeto
make

# Execute os testes
./test_adc_temp
# ou
make run_tests
```

### Para a BitDogLab (Raspberry Pi Pico)

```bash
# Crie um diretório de build para o Pico
mkdir -p build_pico
cd build_pico

# Configure o CMake para o Pico
cmake .. -DBUILD_FOR_PICO=ON

# Compile o projeto
make
```

Após a compilação, será gerado um arquivo `atividade4_pico.uf2` que pode ser carregado na BitDogLab:

1. Conecte a BitDogLab ao computador mantendo o botão BOOTSEL pressionado
2. Solte o botão quando a placa for reconhecida como um dispositivo de armazenamento
3. Copie o arquivo `atividade4_pico.uf2` para a unidade RPI-RP2
4. A placa será reiniciada automaticamente e executará o programa

### Visualizando a Saída do Programa

Para ver a saída do programa na BitDogLab:

1. Conecte a BitDogLab ao computador (sem o botão BOOTSEL pressionado)
2. Use um programa de terminal serial para conectar à porta serial USB da BitDogLab
3. Você verá as leituras de temperatura sendo exibidas a cada segundo

## Teste Implementado

O teste verifica se a função `adc_to_celsius()` retorna corretamente a temperatura de 27°C para um valor de ADC que corresponde a 0.706V.
