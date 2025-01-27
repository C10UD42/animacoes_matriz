#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "animacoes_matriz.pio.h"

#include "lib/matriz_led.h"
#include "lib/buzzer.h"
#include "lib/keypad.h"
#include "animacoes/desenho0.h"
#include "animacoes/desenho1.h"
#include "animacoes/desenho2.h"
#include "animacoes/desenho3.h"
#include "animacoes/desenho4.h"
#include "animacoes/desenho5.h"
#include "animacoes/desenho6.h"
#include "animacoes/desenho7.h"
#include "animacoes/desenho8.h"
#include "animacoes/desenho9.h"
#include "animacoes/desenhoC.h"

#define NUM_ANIMACOES 11
#define NUM_PIXELS 25 // número de pixels

double* animacoes[NUM_ANIMACOES] = {desenho0[0], desenho1[0], desenho2[0], desenho3[0], desenho4[0], desenho5[0], desenho6[0], desenho7[0], desenho8[0], desenho9[0], desenhoC[0]};
// Variáveis globais para cores personalizadas
bool use_custom_colors = false;
double custom_r = 0.0, custom_g = 0.0, custom_b = 0.0;

// Função principal
int main() {
    Keypad keypad;
    init_keypad(&keypad);
    PIO pio = pio0;
    bool ok;
    uint32_t valor_led;
    double r = 0.0, b = 0.0, g = 0.0;

    // Configura a frequência do clock para 128 MHz
    ok = set_sys_clock_khz(128000, false);
    
    // Inicializa a comunicação com a UART
    stdio_init_all();
    printf("Iniciando a transmissão PIO\n");
    if (ok) printf("Clock set to %ld\n", clock_get_hz(clk_sys));

    // Configura a PIO para o programa da matriz de LEDs
    uint offset = pio_add_program(pio, &animacoes_matriz_program);
    uint sm = pio_claim_unused_sm(pio, true);
    animacoes_matriz_program_init(pio, sm, offset, OUT_PIN);

    int frame = 0;
    bool animation_running = false;
    double* animacao_atual = animacoes[0];

    while (true) {
        char pressed_key = keypad_get_key(&keypad);
        if(pressed_key) {
            printf("Tecla pressionada: %c\n", pressed_key);
            use_custom_colors = false;
            switch (pressed_key) {
                case '0':
                    animacao_atual = animacoes[0];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '0' pressionada\n");
                    break;
                case '1':
                    animacao_atual = animacoes[1];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '1' pressionada\n");
                    break;
                case '2':
                    animacao_atual = animacoes[2];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '2' pressionada\n");
                    break;
                case '3':
                    // Ação para a tecla '3'
                    animacao_atual = animacoes[3];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '3' pressionada\n");
                    break;
                case '4':
                    // Ação para a tecla '4'
                    printf("Tecla '4' pressionada\n");
                    break;
                case '5':
                    // Ação para a tecla '5'
                    printf("Tecla '5' pressionada\n");
                    break;
                case '6':
                    // Ação para a tecla '6'
                    inicializar_desenho6();  // Chama a função de inicialização
                    animacao_atual = animacoes[6];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '6' pressionada\n");
                    break;
                case '7':
                    // Ação para a tecla '7'
                    printf("Tecla '7' pressionada\n");
                    break;
                case '8':
                    // Ação para a tecla '8'
                    printf("Tecla '8' pressionada\n");
                    break;
                case '9':
                    // Ação para a tecla '9'
                    animacao_atual = animacoes[9];
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '9' pressionada\n");
                    break;
                case 'A':
                    // Desliga todos os LEDs e para as animações
                    animation_running = false;
                    for (int i = 0; i < NUM_PIXELS; i++) {
                        pio_sm_put_blocking(pio, sm, 0);  // Envia valor 0 para desligar o LED
                    }
                    printf("Tecla 'A' pressionada: Todos os LEDs desligados e animações paradas\n");
                    break;
                case 'B':
                    // Ação para a tecla 'B'
                    printf("Tecla 'B' pressionada\n");
                    break;
                case 'C':
                    // Ação para a tecla 'C'
                    animacao_atual = animacoes[10];
                    custom_r = 0.8;  // Define a cor vermelha
                    custom_g = 0.0;
                    custom_b = 0.0;
                    use_custom_colors = true;
                    animation_running = true;
                    frame = 0;
                    printf("Tecla 'C' pressionada\n");
                    break;
                case 'D':
                    // Ação para a tecla 'D'
                    animacao_atual = animacoes[10];
                    custom_r = 0.0;  // Define a cor verde
                    custom_g = 0.5;
                    custom_b = 0.0;
                    use_custom_colors = true;
                    animation_running = true;
                    frame = 0;
                    printf("Tecla 'D' pressionada\n");
                    break;
                case '#':
                    // Ação para a tecla '#'
                    animacao_atual = animacoes[10];
                    custom_r = 0.2;  // Define a cor branca
                    custom_g = 0.2;
                    custom_b = 0.2;
                    use_custom_colors = true;
                    animation_running = true;
                    frame = 0;
                    printf("Tecla '#' pressionada\n");
                case '*':
                    // Ação para a tecla '*'
                    printf("Tecla '*' pressionada\n");
                default:

                    break;
            }
            
        }
        if (animation_running) {
            desenho_pio(animacao_atual + (frame * 25), valor_led, pio, sm, r, g, b);
            frame = (frame + 1) % 5; // Alterna entre os frames de 0 a 4
        }

        sleep_ms(500);
    }
}
