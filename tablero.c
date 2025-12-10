/* 
**  Fitxer:      tablero.c
**  Data:        2/12/2025
**  Descripció:  Implementació d’operacions sobre el tauler.
*/

#include <stdio.h>
#include "tablero.h"
#include "fichero.h"   

/* TODO: llegir N i subN del fitxer, omplir matriu de caselles i comptadors */
int inicialitzar_tablero(t_tablero *t)
{
    /* TODO:
       - llegir tamany i subtamany amb leer_int_fichero()
       - omplir t->c[i][j] amb inicialitzar_casilla(...)
       - actualitzar caselles_totals i caselles_buides
       - retornar 0 si OK, diferent si error de format
    */
    return 0;
}

/* (FET)TODO: imprimir capçaleres files/columnes i separadors de subquadrats */
void imprimir_tablero(t_tablero t)
{
    int i, j;
    for (i = 0; i < t.tamany; i = i + 1) {
        for (j = 0; j < t.tamany; j = j + 1) {
            printf("%c ", t.c[i][j].car);
        }
        printf("\n");
    }
}

/* TODO: validar rang, comprovar modificable i aplicar canvi */
void realitzar_jugada(t_tablero *t)
{
    /* TODO: lectura d’una jugada (o paràmetres), validacions i aplicació */
}

/* TODO: comprovar final (files, columnes i subquadrats sense duplicats) */
int sudoku_finalitzat(t_tablero t)
{
    /* TODO: retornar 1 si finalitzat, 0 altrament */
    return 0;
}

