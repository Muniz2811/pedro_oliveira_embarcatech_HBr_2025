# Atividade 5 - LED Piscante com Arquitetura Modular

Este projeto implementa um sistema de controle do LED embutido da Raspberry Pi Pico W seguindo uma arquitetura modular de software. O código foi reestruturado para seguir boas práticas de desenvolvimento de software embarcado, com separação clara entre as camadas de hardware, abstração e aplicação.

## Arquitetura do Projeto

O projeto segue uma arquitetura em camadas com três níveis principais:

1. **Drivers (drivers/)**: Controle direto do hardware específico
2. **HAL - Hardware Abstraction Layer (hal/)**: Camada de abstração que fornece uma API simplificada
3. **Aplicação (app/)**: Lógica de alto nível da aplicação

Esta arquitetura proporciona vários benefícios:
- **Portabilidade**: Facilita a migração para diferentes plataformas de hardware
- **Manutenibilidade**: Separa as preocupações, tornando o código mais fácil de entender e modificar
- **Reutilização**: Componentes podem ser reutilizados em diferentes projetos
- **Testabilidade**: Facilita a criação de testes unitários para cada camada

## Estrutura de Diretórios

```
atividade5/
├── app/
│   └── main.c                 # Aplicação principal que faz o LED piscar
├── drivers/
│   └── led_embutido.c         # Driver para controle direto do LED embutido
├── hal/
│   └── hal_led.c              # Camada de abstração para controle de LEDs
├── include/
│   ├── led_embutido.h         # Interface do driver do LED
│   └── hal_led.h              # Interface da camada de abstração
└── CMakeLists.txt             # Configuração de compilação
```

## Descrição dos Componentes

### Camada de Driver (drivers/)

O arquivo `led_embutido.c` implementa o controle direto do LED embutido da Raspberry Pi Pico W usando a API `cyw43_arch`. Esta camada é específica para o hardware da Pico W e seria substituída se o projeto fosse portado para outra plataforma.

Funções principais:
- `led_embutido_init()`: Inicializa o subsistema que controla o LED
- `led_embutido_set()`: Define o estado do LED (ligado/desligado)
- `led_embutido_get()`: Obtém o estado atual do LED

### Camada de Abstração de Hardware (hal/)

O arquivo `hal_led.c` fornece uma interface de alto nível para controle de LEDs, independente do hardware específico. Esta camada usa o driver apropriado internamente, mas expõe uma API consistente para a aplicação.

Funções principais:
- `hal_led_init()`: Inicializa o subsistema de LEDs
- `hal_led_set()`: Define o estado do LED
- `hal_led_get()`: Obtém o estado atual do LED
- `hal_led_toggle()`: Alterna o estado do LED (liga se estiver desligado, desliga se estiver ligado)

### Camada de Aplicação (app/)

O arquivo `main.c` contém a lógica principal da aplicação, que faz o LED piscar em intervalos regulares. Esta camada interage apenas com a HAL, não com os drivers diretamente.

## Como Compilar e Executar

1. Certifique-se de que o SDK do Pico está configurado corretamente
2. Compile o projeto:

```bash
mkdir -p build
cd build
cmake ..
make
```

3. O arquivo `atividade5.uf2` será gerado no diretório `build/`
4. Conecte a Raspberry Pi Pico W ao computador em modo de programação (segurando o botão BOOTSEL)
5. Copie o arquivo `atividade5.uf2` para o volume da Pico W

## Extensibilidade

Este projeto pode ser facilmente estendido para suportar diferentes tipos de LEDs ou outros dispositivos de saída. Para adicionar suporte a um novo tipo de LED:

1. Crie um novo driver na pasta `drivers/`
2. Atualize a camada HAL para usar o novo driver quando apropriado
3. A camada de aplicação não precisa ser modificada, pois usa apenas a interface da HAL

## Conclusão

Esta implementação demonstra como uma arquitetura modular pode ser aplicada mesmo em um projeto simples como fazer um LED piscar. Os princípios utilizados aqui são escaláveis para projetos embarcados muito mais complexos.
