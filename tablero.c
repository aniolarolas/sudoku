/* 
**  Fitxer:      tablero.c
**  Data:        2/12/2025
**  Descripció:  Implementació d’operacions sobre el tauler.
*/

#include <stdio.h>
#include "tablero.h"
#include "fichero.h"
#include "logica.h"
#include "casilla.h"

/* Saltar blancos del fichero usando SOLO la lib fichero.* (no modificable) */
static int es_blanco(char ch)
{
    return (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r');
}

static int leer_siguiente_simbolo(char *out)
{
    char ch;

    if (es_fin_de_fichero()) return 0;

    ch = leer_char_fichero();
    while (!es_fin_de_fichero() && es_blanco(ch)) {
        ch = leer_char_fichero();
    }

    if (es_fin_de_fichero()) return 0;

    *out = ch;
    return 1;
}

/* llegir N i subN del fitxer, omplir matriu de caselles i comptadors */
int inicialitzar_tablero(t_tablero *t)
{
    int i, j;
    int tam, sub;
    char ch;

    tam = leer_int_fichero();
    sub = leer_int_fichero();

    /* Validaciones básicas */
    if (!(tam == 4 || tam == 9 || tam == 16 || tam == 25 || tam == 36)) return 1;
    if (sub <= 0) return 1;
    if (sub * sub != tam) return 1;

    t->tamany = tam;
    t->subtamany = sub;

    t->caselles_totals = tam * tam;
    t->caselles_buides = 0;

    for (i = 0; i < tam; i = i + 1) {
        for (j = 0; j < tam; j = j + 1) {
            if (!leer_siguiente_simbolo(&ch)) return 1;

            inicialitzar_casilla(ch, &t->c[i][j]);

            if (char_a_valor(ch, tam) == 0) t->caselles_buides = t->caselles_buides + 1;
            if (char_a_valor(ch, tam) == -1) return 1; /* símbolo inválido */
        }
    }

    return 0;
}

/* imprimir capçaleres files/columnes i separadors de subquadrats */
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

/* validar rang, comprovar modificable i aplicar canvi */
void realitzar_jugada(t_tablero *t)
{
    int fila1, col1;
    char car;
    int fila, col, valor;

    printf("Jugada (fila col valor): ");
    if (scanf("%d %d %c%*c", &fila1, &col1, &car) != 3) {
        printf("ERROR: entrada invalida.\n");
        return;
    }

    fila = fila1 - 1;
    col  = col1 - 1;

    if (!posicion_en_rango(fila, col, t->tamany)) {
        printf("ERROR: posicion fuera de rango.\n");
        return;
    }

    if (!casilla_modificable(t, fila, col)) {
        printf("ERROR: casilla no modificable.\n");
        return;
    }

    valor = char_a_valor(car, t->tamany);
    if (valor == -1) {
        printf("ERROR: valor invalido.\n");
        return;
    }

    if (!movimiento_valido(t, fila, col, valor)) {
        printf("ERROR: movimiento no valido.\n");
        return;
    }

    aplicar_movimiento(t, fila, col, valor);
}

/* comprovar final (files, columnes i subquadrats sense duplicats) */
int sudoku_finalitzat(t_tablero t)
{
    return sudoku_finalizado(&t);
}
