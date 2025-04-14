# Terceira Tarefa - Sensor de Temperatura Interno do RP2040

Este projeto lê a temperatura interna do microcontrolador RP2040 usando seu sensor de temperatura integrado e mostra o resultado no display OLED.

## Funcionalidades

1. **Leitura de Temperatura**:
   - Utiliza o ADC4 (sensor de temperatura interno)
   - Converte a leitura do ADC para temperatura em graus Celsius
   - Atualiza a cada 500ms

2. **Display OLED**:
   - Mostra o título "Temperatura RP2040"
   - Exibe a temperatura atual com 2 casas decimais
   - Atualização em tempo real

## Componentes Utilizados

- BitDogLab (RP2040)
- Display OLED SSD1306
- Sensor de temperatura interno do RP2040

## Conexões

- **Display OLED**:
  - SDA: GPIO14
  - SCL: GPIO15

## Como Compilar e Executar

1. Certifique-se de ter o SDK do Raspberry Pi Pico configurado
2. Na pasta do projeto, execute:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Copie o arquivo `.uf2` gerado para a BitDogLab

## Funcionamento

O programa realiza os seguintes passos:

1. **Inicialização**:
   - Configura o ADC para o sensor de temperatura
   - Inicializa o display OLED
   - Prepara o buffer de display

2. **Loop Principal**:
   - Lê o valor do sensor de temperatura
   - Converte o valor para temperatura em Celsius
   - Atualiza o display com o novo valor
   - Aguarda 500ms antes da próxima leitura

3. **Conversão de Temperatura**:
   - Converte a leitura do ADC para voltagem
   - Exibe o resultado em graus Celsius

## Observações

- O sensor de temperatura interno do RP2040 tem uma precisão moderada
- A temperatura mostrada é a temperatura interna do chip, que pode ser alguns graus mais alta que a temperatura ambiente
- A atualização a cada 500ms fornece uma boa visualização das mudanças de temperatura
