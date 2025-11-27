/* 
**  Fitxer:      tablero.c
**  Autor:       (Equip)
**  Data:        (AAAA-MM-DD)
**  Descripció:  Implementació d’operacions sobre el tauler.
*/

#include <stdio.h>
#include "tablero.h"
#include "fichero.h"   /* per llegir ints/chars del fitxer proporcionat */

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

/* TODO: imprimir capçaleres files/columnes i separadors de subquadrats */
void imprimir_tablero(t_tablero t)
{
    /* TODO: recorregut per files/columnes i crida a imprimir_casilla */
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

