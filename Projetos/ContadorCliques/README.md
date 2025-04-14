# Tarefa Inicial - Contador Decrescente com Display OLED

Este projeto implementa um contador decrescente controlado por interrupção usando a BitDogLab. O sistema utiliza dois botões (A e B) e um display OLED para mostrar as informações.

## Funcionalidades

1. **Botão A (GPIO5)**:
   - Inicia/Reinicia o contador em 9
   - Ativa a contagem regressiva
   - Zera o contador de cliques do Botão B

2. **Botão B (GPIO6)**:
   - Registra cliques durante a contagem regressiva
   - Os cliques só são contabilizados quando a contagem está ativa (entre 9 e 0)

3. **Display OLED**:
   - Mostra o valor atual do contador
   - Mostra a quantidade de cliques do Botão B

## Componentes Utilizados

- BitDogLab
- Display OLED SSD1306
- Botão A (GPIO5)
- Botão B (GPIO6)

## Conexões

- **Display OLED**:
  - SDA: GPIO14
  - SCL: GPIO15

- **Botões**:
  - Botão A: GPIO5
  - Botão B: GPIO6

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

1. Ao pressionar o Botão A:
   - O contador é iniciado em 9
   - O sistema começa a contagem regressiva
   - O contador de cliques do Botão B é zerado

2. Durante a contagem (9 até 0):
   - O display mostra o valor atual do contador
   - O sistema registra os cliques do Botão B
   - O display mostra o número de cliques do Botão B

3. Quando o contador chega a 0:
   - O sistema para a contagem
   - O display continua mostrando 0 e o número final de cliques
   - Os cliques no Botão B são ignorados

4. Para reiniciar:
   - Pressione o Botão A novamente
   - O processo recomeça do início
