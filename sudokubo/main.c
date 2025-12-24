/*
**  Fitxer:      main.c
**  Descripció:  Punt d’entrada del Sudoku.
*/
#include <stdio.h>
#include "fichero.h"
#include "tablero.h"


int main()
{
    char nom_fichero[SIZE_NOMBRE_FICHERO];
    t_tablero t;

    printf("Intro sudoku file name: ");
    scanf("%79s%*c", nom_fichero);

    if (abrir_fichero(nom_fichero) != ABRIR_FICHERO_OK) {
        printf("Error: El fichero no existe.\n");
        return 1;
    }

    if (inicialitzar_tablero(&t) != 0) {
        printf("Error: formato de fichero no valido.\n");
        cerrar_fichero();
        return 1;
    }

    imprimir_tablero(t);

    while (sudoku_finalitzat(t) == 0) {
        realitzar_jugada(&t);
        imprimir_tablero(t);
    }

    printf("FELICIDADES: Sudoku resuelto! :-)\n");
    cerrar_fichero();
    return 0;
}
