#ifndef MATRIZ_LED_H
#define MATRIZ_LED_H

#include <stdint.h>
#include <stdbool.h>
#include "hardware/pio.h"

// Definindo o número de LEDs
#define NUM_PIXELS 25
#define OUT_PIN 7

// Função para definir a cor RGB de um LED com base na intensidade dos canais
uint32_t matrix_rgb(double b, double r, double g);

// Função para acionar a matriz de LEDs com o valor de cada pixel e cores
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);

void desenho_pio_tecla_d(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);

void desenho_pio_hashtag(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b);

#endif // MATRIZ_LED_H