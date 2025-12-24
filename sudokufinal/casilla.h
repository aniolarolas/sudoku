#ifndef CASILLA_H
#define CASILLA_H

typedef struct {
    char car;          // caràcter de la casella 
    int modificable;   // 1 si l'usuari pot modificar-la, 0 si és fixa
} t_casilla;

// Inicialitza una casella amb un caràcter i si és modificable o no
void init_casilla(t_casilla *c, char car, int modificable);

// Canvia el valor de la casella si és modificable
void canviar_casilla(t_casilla *c, char car);

#endif

