/* 
**  Fitxer:      main.c
**  Data:        27/11/2025
**  Descripció:  Punt d’entrada del Sudoku. Orquestra lectura, inicialització,
**               bucle de jugades i comprovació de final segons rúbrica.
*/

#include <stdio.h>
#include "fichero.h"   
#include "casilla.h"
#include "tablero.h"
#include "colores.h" 

#define SIZE_NOMBRE_FICHERO 64
#define TRUE 1
#define FALSE 0

int main(void){
    
    #include <stdio.h>
#include "casilla.h"
#include "fichero.h"

#define MAX_N 36

int main(void)
{
    int N, subN;
    int i, j;
    char car;

    t_casilla tablero[MAX_N][MAX_N];

    /* Se asume que el fichero ya está abierto */
    /* Leer tamaño y sub-tamaño */
    N = leer_int_fichero();
    subN = leer_int_fichero();

    if (N <= 0 || N > MAX_N || subN <= 0 || subN * subN != N) {
        printf("Error: dimensiones incorrectas\n");
        return 1;
    }

    /* Inicialización de casillas */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

            car = leer_char_fichero();

            /* Ignorar saltos de línea */
            if (car == '\n') {
                j--;
                continue;
            }

            /* Control de fin de fichero */
            if (car == EOF) {
                printf("Error: fin de fichero inesperado\n");
                return 1;
            }

            inicialitzar_casilla(car, &tablero[i][j]);
        }
    }

    /* Mostrar tablero (prueba) */
    printf("\nTablero leído:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            imprimir_casilla(tablero[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    /* Ejemplo de uso de canviar_casilla */
    canviar_casilla(&tablero[0][0], '5');
    
    
    char nom_fichero[SIZE_NOMBRE_FICHERO];
    t_tablero t;

    printf("Intro sudoku file name: ");
    scanf("%79s%*c", nom_fichero);

    /* 1) Obrir fitxer amb la llibreria donada */
    if (abrir_fichero(nom_fichero) != ABRIR_FICHERO_OK) {
        printf("Error: El fichero no existe.\n");
        return 1;
    }

    /* 2) Inicialitzar tauler des del fitxer */
    if (inicialitzar_tablero(&t) != 0) {
        printf("Error: formato de fichero invalido\n");
        cerrar_fichero();
        return 1;
    }

    /* 3) Mostrar tauler inicial */
    imprimir_tablero(t);

    /* 4) Bucle de joc: jugades fins que estigui finalitzat */
    while (sudoku_finalitzat(t) == 0) {
        realitzar_jugada(&t);
        imprimir_tablero(t);
    }

    /* 5) Final */
    printf("SUDOKU FINALIZADO!\n");
    cerrar_fichero();

    return 0;
}
