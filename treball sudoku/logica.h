#ifndef LOGICA_H
#define LOGICA_H

#include "tablero.h"

int char_a_valor(char c, int tam);
char valor_a_char(int v, int tam);

int posicion_en_rango(int fila, int col, int tam);
int valor_en_rango(int v, int tam);

int casilla_modificable(const t_tablero *t, int fila, int col);

int movimiento_valido(const t_tablero *t, int fila, int col, int valor);
void aplicar_movimiento(t_tablero *t, int fila, int col, int valor);

int sudoku_finalizado(const t_tablero *t);

#endif

