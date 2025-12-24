#ifndef CASILLA_H
#define CASILLA_H

typedef struct {
    char car;
    int modificable;
} t_casilla;

char a_majuscula(char c);
void inicialitzar_casilla(char car, t_casilla *c);
void imprimir_casilla(t_casilla c);
void canviar_casilla(t_casilla *c, char car);

#endif
