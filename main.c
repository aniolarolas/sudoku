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

int main(int argc, char *argv[])
{
    /* TODO: validar arguments (nom de fitxer), obrir fitxer i comprovar error */
    if(argc < 2){
        printf("Error: falta nombre del fichero");
    }
    
    /* Ex.: if (argc < 2) { printf("Error: falta fitxer\n"); return 1; }       */
    /* if (abrir_fichero(argv[1]) == ABRIR_FICHERO_ERR) { ... }                */

    t_tablero t;
    /* TODO: inicialitzar tauler (llegir de fitxer via fichero.*) */
    /* if (inicialitzar_tablero(&t) != 0) { ... } */

    /* TODO: imprimir tauler inicial */
    /* imprimir_tablero(t); */

    /* TODO: bucle de joc o seqüència de jugades; cridar realitzar_jugada(&t) */

    /* TODO: comprovar final: if (sudoku_finalitzat(t)) ... */

    /* TODO: tancar fitxer abans d’acabar */
    /* cerrar_fichero(); */

    return 0;
}

