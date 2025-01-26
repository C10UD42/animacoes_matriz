#ifndef DESENHO6_H
#define DESENHO6_H

double desenho6[5][25] = {0};
void inicializar_desenho6() {
    // Preenche os frames com LEDs acesos gradualmente
    for (int frame = 0; frame < 5; ++frame) {
        for (int led = 0; led < (frame + 1) * 5; ++led) {
            desenho6[frame][led] = 1;
        }
    }
}


#endif // DESENHO6_H
