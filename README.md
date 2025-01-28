# Tarefa 02: Geração de Animações em Matriz de LEDs 5x5  

## 📌 Descrição do Projeto

Nesta tarefa, desenvolvemos um sistema utilizando a **Raspberry Pi Pico W** e um **teclado matricial 4x4** para controlar uma **matriz de LEDs RGB WS2812 (5x5)**. O projeto foi implementado no simulador **Wokwi** e permite a execução de diferentes animações através da interação do usuário com o teclado.  

### 🔧 Funcionalidades Implementadas

- 🎨 **10 animações diferentes**, ativadas pelas teclas `0-9`.
- 🎞️ **Cada animação possui pelo menos 5 frames**.
- 🛑 **Parada das animações** com a tecla `A` (desliga todos os LEDs).
- 🔵 **Iluminação Azul** (100%) ao pressionar `B`.
- 🔴 **Iluminação Vermelha** (80%) ao pressionar `C`.
- 🟢 **Iluminação Verde** (50%) ao pressionar `D`.
- ⚪ **Iluminação Branca** (20%) ao pressionar `#`.
- 🔊 **Sinal sonoro** usando quando qualquer tecla é pressionada.
- 🔄 **Modo de gravação** ao pressionar `*` (reboot do Raspberry Pi Pico W).

O sistema foi projetado para ser executado tanto no **simulador Wokwi** quanto em na placa real.  


## 🖥️ Tecnologias Utilizadas

- **Hardware**:  
  - Raspberry Pi Pico W  
  - Teclado Matricial 4x4  
  - Matriz de LEDs RGB WS2812 (5x5)  
  - Buzzer Passivo  

- **Software**:  
  - VS Code com a extensão **Raspberry Pi Pico**  
  - Simulador **Wokwi**  [Wokwi](https://wokwi.com/)
  - SDK do Raspberry Pi Pico  

## 🚀 Como Executar o Projeto

1. Clone este repositório:
   ```sh
   git clone https://github.com/C10UD42/animacoes_matriz.git
   ```
2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>
![image](https://github.com/user-attachments/assets/2979bf13-7094-42fd-8017-70e488cf7b45)

5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/ae4ec514-34cf-4c67-802e-5dfe488ca9eb)

  - Selecione o caminho do projeto<br>
![image](https://github.com/user-attachments/assets/7ff7461f-746a-4149-bc30-60e4cac6a9bf)

6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/f5f07fc3-bb4d-4011-a4f2-9dcc24ffcd54)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>

![image](https://github.com/user-attachments/assets/82822363-1ae1-495f-a7d7-cc78d31fa6ee)

## 📂 Estrutura do Repositório

```
📁 animacoes_matriz
├── 📂 .vscode              # Configurações do VS Code
├── 📂 Fluxograma           # Diagramas do fluxo do sistema
│   ├── diagrama.png        # Imagem do diagrama
├── 📂 Trello               # Organização do projeto e tarefas
├── 📂 Video                # Vídeos da execução do projeto
│   ├── simulacao_wokwi.mp4 # Simulação no Wokwi
│   ├── hardware_demo.mp4   # Teste em hardware real
├── 📂 src                  # Código-fonte principal
│   ├── main.c              # Código principal
│   ├── 📂 animacoes        # Arquivos das animações
│   ├── 📂 lib              # Bibliotecas auxiliares
│   │   ├── keyboard.c      # Interação com o teclado matricial
│   │   ├── led_matrix.c    # Controle da matriz de LEDs
│   │   ├── buzzer.c        # Controle do buzzer

├── .gitignore              # Arquivo para ignorar arquivos desnecessários no Git
├── CMakeLists.txt          # Configuração do CMake para compilação
├── README.md               # Este arquivo
├── animacoes_matriz.pio    # Arquivo de configuração da matriz de LEDs
├── diagram.json            # Arquivo de simulação do Wokwi
├── pico_sdk_import.cmake   # Configuração do SDK para Raspberry Pi Pico
└── wokwi.toml              # Configuração do simulador Wokwi
```
## Fluxo do Sistema  

Abaixo está o diagrama de fluxo que representa o funcionamento do sistema, desde a inicialização até a execução das ações baseadas nas entradas do usuário.  

![Fluxograma](https://github.com/user-attachments/assets/d2331372-50af-4ebd-ba93-b7ea63d9e7ad)

1. **Inicialização do Sistema**  
   - Configuração do clock para **128 MHz**.  
   - Inicialização dos dispositivos: **Matriz de LEDs, Buzzer, UART e Teclado (Keypad)**.  

2. **Entrada do Usuário**  
   - O sistema aguarda uma tecla ser pressionada no **Keypad**.  

3. **Determinação da Ação**  
   Dependendo da tecla pressionada, o sistema executa uma das seguintes ações:  
   - **Exibição de Animação na Matriz de LEDs** (teclas numéricas).  
   - **Configuração de Cores Personalizadas** (tecla `#`).  
   - **Parada das Animações e desligamento dos LEDs** (tecla `A`).  
   - **Modo de Gravação USB** (tecla `*`).  

4. **Execução da Ação Selecionada**  
   - Se for uma **animação**, o sistema gerencia os frames e atualiza continuamente a matriz.  
   - Se for uma **configuração de cor**, os valores **RGB** são ajustados.  
   - Se for um **comando especial** (`A` ou `*`), ele é processado imediatamente.  

5. **Saída**  
   - Exibição da **animação** na matriz de LEDs ou execução da **ação correspondente**.  
   - O sistema funciona de forma **interativa e cíclica**, sempre esperando novas entradas do usuário.  

## 📹 Demonstração em Vídeo

Assista ao vídeo demonstrativo do funcionamento do sistema:  


O projeto suporta a simulação completa do circuito no Wokwi. Para visualizar a simulação, acesse:  
🔗 [Simulação no Wokwi](https://www.youtube.com/watch?v=cUP6fKhihbE)  
[![Simulação no Wokwi](https://img.youtube.com/vi/cUP6fKhihbE/0.jpg)](https://www.youtube.com/watch?v=cUP6fKhihbE)  


Além disso, realizamos testes em hardware real utilizando a **Raspberry Pi Pico W**. Confira o vídeo da execução prática:  
🔗 [Teste em Hardware](https://www.youtube.com/watch?v=BInLH3Vq7gM)  
[![Teste em Hardware](https://img.youtube.com/vi/BInLH3Vq7gM/0.jpg)](https://www.youtube.com/watch?v=BInLH3Vq7gM)  


## 👥 Equipe de Desenvolvimento

| Nome | GitHub |
|------|--------|
| **Líder:** Claudemir da Silva | [@C10UD42](https://github.com/C10UD42) |
| Elisson Nadson | [@ElissonNadson](https://github.com/ElissonNadson) |
| Lucas Emanoel | [@lucasfix](https://github.com/lucasfix) |
| Davi Moura | [@davims9](https://github.com/davims9) |
| Ariel Pina | [@apribeiro-cic](https://github.com/apribeiro-cic) |
| Marcus Porto | [@marcusporto](https://github.com/marcusporto) |
| Guilherme Lopes | [@GuilhermeFRLopes](https://github.com/GuilhermeFRLopes) |


⌨️ Desenvolvido com 💙 por **C10UD42** e equipe 🚀
