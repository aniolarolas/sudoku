/* 
**  Fitxer:      casilla.h
**  Autor:       (Equip)
**  Data:        (AAAA-MM-DD)
**  Descripció:  Definició de t_casilla i prototips d’operacions sobre casella.
*/
#ifndef CASILLA_H
#define CASILLA_H

/* Fichers de capçalera del sistema (si calgués) */
/* #include <stdio.h> */

/* Constants simbòliques (si calgués) */
/* #define ... */

/* Tipus de dades */
typedef struct {
    char car;        /* ' ', '0'..'9', 'a'..'z', 'A'..'Z' */
    int  modificable;/* 0 no, 1 si */
} t_casilla;

/* Prototips de funcions (accions sobre casella) */
void inicialitzar_casilla(char car, t_casilla *c);
void imprimir_casilla(t_casilla c);
void canviar_casilla(t_casilla *c, char car);

#endif /* CASILLA_H */

