#ifndef LOGICA_H
#define LOGICA_H

#include "tablero.h"

/* Conversión carácter <-> valor interno (0..tam-1) */
int char_a_valor(char c, int tam);
char valor_a_char(int v, int tam);

/* Comprobaciones de rango */
int posicion_en_rango(int fila, int col, int tam);
int valor_en_rango(int v, int tam);

/* Casilla modificable */
int casilla_modificable(const t_tablero *t, int fila, int col);

/* Validación de movimientos */
int movimiento_valido(const t_tablero *t, int fila, int col, int valor);

/* Aplicar movimiento */
void aplicar_movimiento(t_tablero *t, int fila, int col, int valor);

/* Comprobación de sudoku finalizado */
int sudoku_finalizado(const t_tablero *t);

#endif

