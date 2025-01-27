#include <stdint.h>
#include <stdbool.h>
#include "hardware/pio.h"
#include "matriz_led.h"
#include "hardware/clocks.h"

// Definindo o número de LEDs
#define NUM_PIXELS 25

// Variável global para usar cores personalizadas
extern bool use_custom_colors;
extern double custom_r, custom_g, custom_b;

// Função para definir a cor RGB de um LED com base na intensidade dos canais
uint32_t matrix_rgb(double b, double r, double g);

double intensidade = 1;

#include <stdio.h>
#include "animacoes_matriz.pio.h"
#include "hardware/pio.h"

// Função para definir a cor RGB de um LED
uint32_t matrix_rgb(double b, double r, double g)
{
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

// Função para acionar a matriz de LEDs com o valor de cada pixel e cores
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)
{
    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        // Ajusta a intensidade de cada LED
        double pixel_val = desenho[24 - i] * intensidade;  // Aplica intensidade

        if (use_custom_colors) {
            // Use cores personalizadas
            valor_led = matrix_rgb(custom_b, custom_r, custom_g);
        } else {
            // Use a lógica padrão para definir as cores
            if (i % 2 == 0) {
                valor_led = matrix_rgb(pixel_val, r = 0.0, g = 0.0);
            } else {
                valor_led = matrix_rgb(b = 0.0, pixel_val, g = 0.0);
            }
        }

        pio_sm_put_blocking(pio, sm, valor_led);
    }
}
