#include "logica.h"

/* Vacío */
static int es_vacia_char(char c)
{
    return (c == '.') || (c == '-');
}

/* ------------------ Conversión carácter -> valor ------------------ */
/* Devuelve:
 *   0 si vacío ('.' o '-')
 *   1..tam si válido
 *  -1 si inválido
 */
int char_a_valor(char c, int tam) {
    int v;

    if (es_vacia_char(c)) return 0;

    if (c >= '1' && c <= '9') {
        v = c - '0'; /* 1..9 */
        if (v >= 1 && v <= tam) return v;
        return -1;
    }

    if (c == '0') {
        /* '0' es símbolo válido SOLO en 16/25/36 y representa el tamaño */
        if (tam == 16 || tam == 25 || tam == 36) return tam;
        return -1;
    }

    if (c >= 'A' && c <= 'Z') {
        v = 10 + (c - 'A'); /* A=10 ... Z=35 */
        if (v >= 1 && v <= tam) return v;
        return -1;
    }

    return -1;
}

/* ------------------ Conversión valor -> carácter ------------------ */
char valor_a_char(int v, int tam) {
    if (v == 0) return '.';

    if (v >= 1 && v <= 9) return (char)('0' + v);

    if (v == tam && (tam == 16 || tam == 25 || tam == 36)) return '0';

    if (v >= 10 && v <= 35) return (char)('A' + (v - 10));

    return '?';
}

/* ------------------ Rango ------------------ */
int posicion_en_rango(int fila, int col, int tam) {
    return fila >= 0 && fila < tam && col >= 0 && col < tam;
}

int valor_en_rango(int v, int tam) {
    return v >= 0 && v <= tam;
}

/* ------------------ Casilla modificable ------------------ */
int casilla_modificable(const t_tablero *t, int fila, int col) {
    if (!posicion_en_rango(fila, col, t->tamany)) return 0;
    return (t->c[fila][col].modificable != 0);
}

/* ------------------ Movimiento válido ------------------ */
int movimiento_valido(const t_tablero *t, int fila, int col, int valor) {
    int i, j;
    int tam, sub;
    int ini_f, ini_c;

    tam = t->tamany;
    sub = t->subtamany;

    /* 1. comprobar rangos */
    if (!posicion_en_rango(fila, col, tam)) return 0;
    if (!casilla_modificable(t, fila, col)) return 0;
    if (!valor_en_rango(valor, tam)) return 0;

    /* permitir borrar */
    if (valor == 0) return 1;

    /* 2. recorrer fila */
    for (j = 0; j < tam; j = j + 1) {
        if (j != col) {
            int v = char_a_valor(t->c[fila][j].car, tam);
            if (v == valor) return 0;
        }
    }

    /* 3. recorrer columna */
    for (i = 0; i < tam; i = i + 1) {
        if (i != fila) {
            int v = char_a_valor(t->c[i][col].car, tam);
            if (v == valor) return 0;
        }
    }

    /* 4. recorrer subcuadrado */
    ini_f = (fila / sub) * sub;
    ini_c = (col  / sub) * sub;

    for (i = ini_f; i < ini_f + sub; i = i + 1) {
        for (j = ini_c; j < ini_c + sub; j = j + 1) {
            if (!(i == fila && j == col)) {
                int v = char_a_valor(t->c[i][j].car, tam);
                if (v == valor) return 0;
            }
        }
    }

    return 1;
}

/* ------------------ Aplicar movimiento ------------------ */
void aplicar_movimiento(t_tablero *t, int fila, int col, int valor) {
    int tam;
    int antes;

    tam = t->tamany;
    antes = char_a_valor(t->c[fila][col].car, tam);

    /* actualizar casillas_buides si procede */
    if (antes == 0 && valor != 0) t->caselles_buides = t->caselles_buides - 1;
    if (antes != 0 && valor == 0) t->caselles_buides = t->caselles_buides + 1;

    t->c[fila][col].car = valor_a_char(valor, tam);
}

/* ------------------ Sudoku finalizado ------------------ */
int sudoku_finalizado(const t_tablero *t) {
    int i, j, bi, bj;
    int tam, sub;

    tam = t->tamany;
    sub = t->subtamany;

    /* 1. comprobar casillas_buides */
    if (t->caselles_buides != 0) return 0;

    /* 2. comprobar filas y 3. columnas */
    for (i = 0; i < tam; i = i + 1) {
        int visto_f[37];
        int visto_c[37];

        for (j = 0; j <= 36; j = j + 1) {
            visto_f[j] = 0;
            visto_c[j] = 0;
        }

        for (j = 0; j < tam; j = j + 1) {
            int vf = char_a_valor(t->c[i][j].car, tam);
            int vc = char_a_valor(t->c[j][i].car, tam);

            if (vf <= 0 || vf > tam) return 0;
            if (vc <= 0 || vc > tam) return 0;

            if (visto_f[vf]) return 0;
            if (visto_c[vc]) return 0;

            visto_f[vf] = 1;
            visto_c[vc] = 1;
        }
    }

    /* 4. comprobar subcuadrados */
    for (bi = 0; bi < tam; bi = bi + sub) {
        for (bj = 0; bj < tam; bj = bj + sub) {
            int visto[37];

            for (i = 0; i <= 36; i = i + 1) visto[i] = 0;

            for (i = bi; i < bi + sub; i = i + 1) {
                for (j = bj; j < bj + sub; j = j + 1) {
                    int v = char_a_valor(t->c[i][j].car, tam);
                    if (v <= 0 || v > tam) return 0;
                    if (visto[v]) return 0;
                    visto[v] = 1;
                }
            }
        }
    }

    return 1;
}
