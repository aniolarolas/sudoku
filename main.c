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
    
    int N, subN;
    int i, j;
    char car;
    t_casilla **tablero;

    /* Comprobación de argumentos */
    if (argc != 2) {
        printf("Uso: %s <fichero_entrada>\n", argv[0]);
        return 1;
    }

    /* Abrir fichero */
    if (abrir_fichero(argv[1]) != ABRIR_FICHERO_OK) {
        printf("Error: no se ha podido abrir el fichero\n");
        return 1;
    }

    /* Leer tamaño y sub-tamaño */
    N = leer_int_fichero();
    subN = leer_int_fichero();

    if (N <= 0 || subN <= 0 || subN * subN != N) {
        printf("Error: dimensiones incorrectas\n");
        cerrar_fichero();
        return 1;
    }

    /* Reserva del tablero de casillas */
    tablero = (t_casilla **)malloc(N * sizeof(t_casilla *));
    if (tablero == NULL) {
        printf("Error de memoria\n");
        cerrar_fichero();
        return 1;
    }

    for (i = 0; i < N; i++) {
        tablero[i] = (t_casilla *)malloc(N * sizeof(t_casilla));
        if (tablero[i] == NULL) {
            printf("Error de memoria\n");
            cerrar_fichero();
            return 1;
        }
    }

    /* Lectura del contenido e inicialización de casillas */
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
                cerrar_fichero();
                return 1;
            }

            /* Inicializar casilla */
            inicialitzar_casilla(car, &tablero[i][j]);
        }
    }

    cerrar_fichero();

    /* Impresión del tablero (prueba) */
    printf("\nTablero leído:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            imprimir_casilla(tablero[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    /* Ejemplo de cambio de casilla */
    canviar_casilla(&tablero[0][0], '5');

    /* Liberar memoria */
    for (i = 0; i < N; i++) {
        free(tablero[i]);
    }
    free(tablero);
    
    
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
