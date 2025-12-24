#ifndef CASILLA_H
#define CASILLA_H

typedef struct {
    char car;
    int modificable;
} t_casilla;

void inicialitzar_casilla(char car, t_casilla *c);
void imprimir_casilla(t_casilla c);
void canviar_casilla(t_casilla *c, char car);

#endif

