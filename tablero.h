/* 
**  Fitxer:      tablero.h
**  Data:        2/12/2025
**  Descripció:  Estructura del tauler i prototips d’operacions de tauler.
*/
#ifndef TABLERO_H
#define TABLERO_H

#include "casilla.h"

#define MAX_F 36
#define MAX_C 36
#define TRUE 1
#define FALSE 0

/* Tipus de dades: tauler amb metadades */
typedef struct {
    t_casilla c[MAX_F][MAX_C];
    int tamany;            /* 4, 9, 16, 25, 36 */
    int subtamany;         /* 2, 3, 4, 5, 6    */
    int caselles_buides;
    int caselles_totals;
} t_tablero;

/*Prototips funcions*/
int  inicialitzar_tablero(t_tablero *t);
void imprimir_tablero(t_tablero t);
void realitzar_jugada(t_tablero *t);
int  sudoku_finalitzat(t_tablero t);

#endif /* TABLERO_H */
