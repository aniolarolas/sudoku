#include <stdio.h>
#include "casilla.h"
#include "colores.h"

/* Convertir lletra minúscula a majúscula */
char a_majuscula(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int es_casella_buida(char c)
{
    return (c == '.') || (c == '-') || (c == ' ');
}

void inicialitzar_casilla(char car, t_casilla *c)
{
    car = a_majuscula(car);
    c->car = car;
    if (es_casella_buida(car)) c->modificable = 1;
    else c->modificable = 0;
}

void imprimir_casilla(t_casilla c)
{
    if (c.modificable == 0) {
        printf_color_negrita();
        if (es_casella_buida(c.car)) printf(" ");
        else printf("%c", c.car);
        printf_reset_color();
    } else {
        if (es_casella_buida(c.car)) printf(" ");
        else printf("%c", c.car);
    }
}

void canviar_casilla(t_casilla *c, char car)
{
    if (c->modificable != 0) {
        c->car = a_majuscula(car);
    }
}
