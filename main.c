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
    }
    
    
    t_tablero t;
    t.tamany = 0;
    t.subtamany = 0;
    t.caselles_buides = 0;
    t.caselles_totals = 0;

    {
        int i, j;

        /* Capçalera: tamany i subtamany */
        if (fscanf(fp, "%d %d", &t.tamany, &t.subtamany) != 2) {
            printf("Error: formato de cabecera invalido\n");
            fclose(fp);
            return 1;
        }

        /* Matriu: N×N caràcters (separats per espais o salts de línia) */
        for (i = 0; i < t.tamany; i = i + 1) {
            for (j = 0; j < t.tamany; j = j + 1) {
                char ch;
                if (fscanf(fp, " %c", &ch) != 1) {  /* l'espai salta blancs */
                    printf("Error: formato de datos invalido\n");
                    fclose(fp);
                    return 1;
                }
                t.c[i][j].car = ch;
                t.c[i][j].modificable = 1;  /* S2: placeholder; es refinarà a S3 */
            }
        }

        t.caselles_totals = t.tamany * t.tamany;
        t.caselles_buides = 0;

        imprimir_tablero(t);
    }

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

