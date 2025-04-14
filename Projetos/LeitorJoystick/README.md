# Segunda Tarefa - Leitura do Joystick com Display OLED

Este projeto implementa a leitura dos valores do joystick da BitDogLab e exibe os resultados no display OLED.

## Funcionalidades

1. **Leitura do Joystick**:
   - Eixo X (ADC0 - GPIO26)
   - Eixo Y (ADC1 - GPIO27)
   - Botão (GPIO22)

2. **Display OLED**:
   - Mostra os valores X e Y do joystick
   - Mostra o estado do botão (PRESSED/RELEASED)

## Componentes Utilizados

- BitDogLab
- Display OLED SSD1306
- Joystick Analógico

## Conexões

- **Display OLED**:
  - SDA: GPIO14
  - SCL: GPIO15

- **Joystick**:
  - Eixo X: GPIO26 (ADC0)
  - Eixo Y: GPIO27 (ADC1)
  - Botão: GPIO22

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

1. O programa lê continuamente os valores do joystick:
   - Valores X e Y através do ADC
   - Estado do botão através do GPIO

2. Os valores são mostrados no display OLED:
   - Primeira linha: Valor X (0-4095)
   - Segunda linha: Valor Y (0-4095)
   - Terceira linha: Estado do botão

3. O display é atualizado a cada 50ms para uma boa responsividade

## Observações

- Os valores do ADC variam de 0 a 4095 (12 bits)
- O botão do joystick é ativo em baixo (LOW quando pressionado)