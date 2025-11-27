/* 
**  Fitxer:      casilla.c
**  Autor:       (Equip)
**  Data:        (AAAA-MM-DD)
**  Descripció:  Implementació de les operacions sobre t_casilla.
*/

#include "casilla.h"
/* #include <stdio.h>  // si s’usa printf a imprimir_casilla */

/* TODO: inicialitzar camp car i el flag modificable segons origen (fitxer) */
void inicialitzar_casilla(char car, t_casilla *c)
{
    /* TODO: c->car = car; c->modificable = ... */
}

/* TODO: imprimir el contingut de la casella segons l’estil acordat */
void imprimir_casilla(t_casilla c)
{
    /* TODO: printf("%c", c.car);  (o integració amb colores, si escau) */
}

/* TODO: canviar valor només si modificable == 1 */
void canviar_casilla(t_casilla *c, char car)
{
    /* TODO: if (c->modificable) { c->car = car; } */
}

