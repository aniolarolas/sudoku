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