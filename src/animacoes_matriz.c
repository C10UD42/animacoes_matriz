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

#define NUM_ANIMACOES 10

double* animacoes[NUM_ANIMACOES] = {desenho0[0], desenho1[0], desenho2[0], desenho3[0], desenho4[0], desenho5[0], desenho6[0], desenho7[0], desenho8[0], desenho9[0]};

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
                    // Ação para a tecla '2'
                    printf("Tecla '2' pressionada\n");
                    break;
                case '3':
                    // Ação para a tecla '3'
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
                    printf("Tecla '9' pressionada\n");
                    break;
                case 'A':
                    // Ação para a tecla 'A'
                    printf("Tecla 'A' pressionada\n");
                    break;
                case 'B':
                    // Ação para a tecla 'B'
                    printf("Tecla 'B' pressionada\n");
                    break;
                case 'C':
                    // Ação para a tecla 'C'
                    printf("Tecla 'C' pressionada\n");
                    break;
                case 'D':
                    // Ação para a tecla 'D'
                    printf("Tecla 'D' pressionada\n");
                    break;
                case '#':
                    // Ação para a tecla '#'
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
