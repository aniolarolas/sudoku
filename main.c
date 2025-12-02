/* 
**  Fitxer:      main.c
**  Data:        27/11/2025
**  Descripció:  Punt d’entrada del Sudoku. Orquestra lectura, inicialització,
**               bucle de jugades i comprovació de final segons rúbrica.
*/

#include <stdio.h>
#include "fichero.h"   /* Llibreria base proporcionada */
#include "casilla.h"
#include "tablero.h"
#include "colores.h" 

#define SIZE_NOMBRE_FICHERO 64
#define TRUE 1
#define FALSE 0

int main(void){
    char nom_fichero[SIZE_NOMBRE_FICHERO];
    FILE *fp;
    
    printf("Intro sudoku file name: ");
    scanf("%63s", nom_fichero);
    fp = fopen(nom_fichero, "r");

    if(fp == NULL){
        printf("Error: El fichero no existe.");
        return 1;
    }else{
        /*TODO: función inicializarTablero*/
    }
    

    t_tablero t;
    /* TODO: inicialitzar tauler (llegir de fitxer via fichero.*) */
    /* if (inicialitzar_tablero(&t) != 0) { ... } */

    /* TODO: imprimir tauler inicial */
    /* imprimir_tablero(t); */

    /* TODO: bucle de joc o seqüència de jugades; cridar realitzar_jugada(&t) */

    /* TODO: comprovar final: if (sudoku_finalitzat(t)) ... */

    /* TODO: tancar fitxer abans d’acabar */
    /* cerrar_fichero(); */

    fclose(fp);
    
    return 0;
}

