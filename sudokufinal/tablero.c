#include <stdio.h>
#include "tablero.h"
#include "fichero.h"
#include "logica.h"
#include "casilla.h"
#include "colores.h"

int calcular_subtamany(int tam)
{
    int s;
    if (tam == 0) return 0;
    if (tam == 1) return 1;
    for (s = 1; s <= 6; s = s + 1) {
        if (s * s == tam) return s;
    }
    return -1;
}

int saltar_fins_fi_linia()
{
    char ch;
    if (es_fin_de_fichero()) return 0;
    ch = leer_char_fichero();
    while (!es_fin_de_fichero() && ch != '\n') {
        ch = leer_char_fichero();
    }
    return 1;
}

int llegir_casella(char *out)
{
    char ch;

    if (es_fin_de_fichero()) return 0;
    ch = leer_char_fichero();

    while (!es_fin_de_fichero() && (ch == '\n' || ch == '\r')) {
        ch = leer_char_fichero();
    }

    if (es_fin_de_fichero()) return 0;

    *out = ch;
    return 1;
}

int inicialitzar_tablero(t_tablero *t)
{
    int i, j;
    int tam, sub;
    char ch;
    int v;

    tam = leer_int_fichero();
    sub = calcular_subtamany(tam);

    if (!(tam == 0 || tam == 1 || tam == 4 || tam == 9 || tam == 16 || tam == 25 || tam == 36)) return 1;
    if (sub == -1) return 1;

    t->tamany = tam;
    t->subtamany = sub;
    t->caselles_totals = tam * tam;
    t->caselles_buides = 0;

    saltar_fins_fi_linia();

    for (i = 0; i < tam; i = i + 1) {
        for (j = 0; j < tam; j = j + 1) {
            if (!llegir_casella(&ch)) return 1;

            v = char_a_valor(ch, tam);
            if (v == -1) return 1;

            inicialitzar_casilla(ch, &t->c[i][j]);

            if (v == 0) t->caselles_buides = t->caselles_buides + 1;
        }
        saltar_fins_fi_linia();
    }

    return 0;
}

int es_blanco(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
}

int leer_siguiente_simbolo(char *out)
{
    char ch;
    if (out == NULL) return 0;
    if (es_fin_de_fichero()) return 0;
    ch = leer_char_fichero();
    while (!es_fin_de_fichero() && es_blanco(ch)) {
        ch = leer_char_fichero();
    }
    if (es_fin_de_fichero()) return 0;
    *out = ch;
    return 1;
}

char indice_a_char(int idx)
{
    if (idx >= 0 && idx <= 9) return (char)('0' + idx);
    if (idx >= 10 && idx <= 35) return (char)('A' + (idx - 10));
    return '?';
}

int char_a_indice(char ch)
{
    if (ch >= '0' && ch <= '9') return (int)(ch - '0');
    if (ch >= 'A' && ch <= 'Z') return 10 + (int)(ch - 'A');
    return -1;
}

void imprimir_cabecera_columnas(int tam, int sub)
{
    int j;
    printf(" |");
    if (tam == 0) {
        printf("\n");
        return;
    }
    for (j = 0; j < tam; j = j + 1) {
        printf("%c", indice_a_char(j));
        if (j == tam - 1) {
            printf("|");
        } else if (((j + 1) % sub) == 0) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void imprimir_separador_horizontal(int tam, int sub)
{
    int j;
    printf("-");
    for (j = 0; j < tam; j = j + 1) {
        printf("+-");
    }
    printf("+\n");
    (void)sub;
}

void imprimir_fila_tablero(t_tablero t, int fila)
{
    int j;
    int tam = t.tamany;
    int sub = t.subtamany;

    printf("%c|", indice_a_char(fila));
    printf_reset_color();

    for (j = 0; j < tam; j = j + 1) {
        imprimir_casilla(t.c[fila][j]);
        if (j == tam - 1) {
            printf("|");
        } else if (((j + 1) % sub) == 0) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void imprimir_tablero(t_tablero t)
{
    int i;
    int tam = t.tamany;
    int sub = t.subtamany;

    printf_reset_color();
    printf_color_negrita();
    printf("\n");

    imprimir_cabecera_columnas(tam, sub);
    imprimir_separador_horizontal(tam, sub);

    for (i = 0; i < tam; i = i + 1) {
        imprimir_fila_tablero(t, i);
        if (((i + 1) % sub) == 0) {
            imprimir_separador_horizontal(tam, sub);
        }
    }

    printf_reset_color();
    printf("\n");
}

void realitzar_jugada(t_tablero *t)
{
    char cf, cc, cv;
    int fila, col;
    int valor;

    printf("Intro [fila col car] sin espacios: ");
    if (scanf(" %c%c%c%*c", &cf, &cc, &cv) != 3) return;

    fila = char_a_indice(cf);
    col  = char_a_indice(cc);
    if (fila < 0 || col < 0) return;
    if (fila >= t->tamany || col >= t->tamany) return;

    valor = char_a_valor(cv, t->tamany);
    if (valor == -1) return;

    if (!casilla_modificable(t, fila, col)) return;
    if (!valor_en_rango(valor, t->tamany)) return;
    aplicar_movimiento(t, fila, col, valor);
}

int sudoku_finalitzat(t_tablero t)
{
    return sudoku_finalizado(&t);
}


