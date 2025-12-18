#include "logica.h"

/* ------------------ Conversión carácter -> valor ------------------ */
int char_a_valor(char c, int tam) {
    /* TODO:
     *  - convertir '1'..'9'
     *  - convertir 'A'..'Z'
     *  - tratar '0' para 16/25/36
     *  - comprobar rango
     */
    return -1;
}

/* ------------------ Conversión valor -> carácter ------------------ */
char valor_a_char(int v, int tam) {
    /* TODO:
     *  - v en 0..tam-1
     *  - devolver '1'..'9', 'A'..'Z' o '0'
     */
    return '?';
}

/* ------------------ Rango ------------------ */
int posicion_en_rango(int fila, int col, int tam) {
    return fila >= 0 && fila < tam && col >= 0 && col < tam;
}

int valor_en_rango(int v, int tam) {
    return v >= 0 && v < tam;
}

/* ------------------ Casilla modificable ------------------ */
int casilla_modificable(const t_tablero *t, int fila, int col) {
    /* TODO:
     *  - comprobar rango
     *  - devolver 0 si la casilla es fija
     */
    return 0;
}

/* ------------------ Movimiento válido ------------------ */
int movimiento_valido(const t_tablero *t, int fila, int col, int valor) {
    /* TODO:
     * 1. comprobar rangos
     * 2. recorrer fila
     * 3. recorrer columna
     * 4. recorrer subcuadrado
     * 5. detectar duplicados
     */
    return 0;
}

/* ------------------ Aplicar movimiento ------------------ */
void aplicar_movimiento(t_tablero *t, int fila, int col, int valor) {
    /* TODO:
     *  - actualizar valor de la casilla
     *  - actualizar casillas_buides si procede
     */
}

/* ------------------ Sudoku finalizado ------------------ */
int sudoku_finalizado(const t_tablero *t) {
    /* TODO:
     * 1. comprobar casillas_buides
     * 2. comprobar filas
     * 3. comprobar columnas
     * 4. comprobar subcuadrados
     */
    return 0;
}

