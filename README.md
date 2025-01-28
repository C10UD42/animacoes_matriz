```md
# Animações em Matriz de LEDs 5x5

Este repositório contém a implementação de animações para uma matriz de LEDs 5x5, utilizando o **Raspberry Pi Pico W** e um **teclado matricial 4x4**, desenvolvido no simulador **Wokwi**.

## 📌 Descrição do Projeto

O projeto tem como objetivo gerar diferentes animações de curta duração em uma matriz **WS2812** RGB controlada pelo **Raspberry Pi Pico W**. O sistema permite interações através de um **teclado matricial 4x4**, onde diferentes teclas acionam animações e configurações de iluminação.

### 🔧 Funcionalidades Implementadas

- 🎨 **10 animações diferentes**, ativadas pelas teclas `0-9`.
- 🎞️ **Cada animação possui pelo menos 5 frames**, garantindo fluidez.
- 🛑 **Parada das animações** com a tecla `A` (desliga todos os LEDs).
- 🔵 **Iluminação Azul** (100%) ao pressionar `B`.
- 🔴 **Iluminação Vermelha** (80%) ao pressionar `C`.
- 🟢 **Iluminação Verde** (50%) ao pressionar `D`.
- ⚪ **Iluminação Branca** (20%) ao pressionar `#`.
- 🔊 **Sinal sonoro opcional** usando um buzzer em uma animação.
- 🔄 **Modo de gravação** ao pressionar `*` (reboot do Raspberry Pi Pico W).

## 🖥️ Tecnologias Utilizadas

- **Linguagem:** C
- **Plataforma de Simulação:** [Wokwi](https://wokwi.com/)
- **Microcontrolador:** Raspberry Pi Pico W
- **Bibliotecas:** Pico SDK
- **Editor de Código:** VS Code
- **Controle de Versão:** Git & GitHub

## 🚀 Como Executar o Projeto

1. Clone este repositório:
   ```sh
   git clone https://github.com/C10UD42/animacoes_matriz.git
   cd animacoes_matriz
   ```

2. Instale o **Pico SDK** seguindo a [documentação oficial](https://github.com/raspberrypi/pico-sdk).

3. Compile e rode o código:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Suba o código para o Raspberry Pi Pico W.

5. Para simulação no **Wokwi**, abra o arquivo `.wokwi` e execute o ambiente.

## 📂 Estrutura do Repositório

```
📁 animacoes_matriz
├── 📂 src
│   ├── main.c            # Código principal
│   ├── animations.c      # Funções das animações
│   ├── keyboard.c        # Interação com o teclado matricial
│   ├── led_matrix.c      # Controle da matriz de LEDs
│   ├── buzzer.c          # Controle do buzzer (opcional)
├── 📂 include
│   ├── animations.h
│   ├── keyboard.h
│   ├── led_matrix.h
│   ├── buzzer.h
├── 📁 build              # Diretório de compilação
├── CMakeLists.txt        # Configuração do CMake
├── README.md             # Este arquivo
└── .wokwi-config.json    # Arquivo de simulação Wokwi
```

## 📹 Demonstração em Vídeo

Assista ao vídeo demonstrativo do funcionamento do sistema:  
🔗 [Vídeo do Sistema com a Placa](https://github.com/C10UD42/animacoes_matriz/video1.mp4)  
🔗 [Vídeo Tutorial de Implementação](https://github.com/C10UD42/animacoes_matriz/video2.mp4)

## 👥 Equipe de Desenvolvimento

| Nome | GitHub | Commits |
|------|--------|---------|
| **Líder:** C10UD42 | [@C10UD42](https://github.com/C10UD42) | 5 |
| ElissonNadson | [@ElissonNadson](https://github.com/ElissonNadson) | 11 |
| davims9 | [@davims9](https://github.com/davims9) | 3 |
| apribeiro-cic | [@apribeiro-cic](https://github.com/apribeiro-cic) | 1 |
| marcusporto | [@marcusporto](https://github.com/marcusporto) | 1 |
| GuilhermeFRLopes | [@GuilhermeFRLopes](https://github.com/GuilhermeFRLopes) | 1 |
| lucasfix | [@lucasfix](https://github.com/lucasfix) | 1 |

---

⌨️ Desenvolvido com 💙 por **C10UD42** e equipe 🚀
```

Agora o `README.md` inclui todos os colaboradores com seus commits e destaca o líder do projeto. Se precisar de mais ajustes, é só avisar! 🚀
