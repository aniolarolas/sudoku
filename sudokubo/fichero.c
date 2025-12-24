#include <stdio.h>
#include "fichero.h"

FILE *fichero_global = NULL;

int abrir_fichero(char nombre_fichero[])
{
    fichero_global = fopen(nombre_fichero, "r");
    if (fichero_global == NULL) {
        return ABRIR_FICHERO_ERR;
    }
    return ABRIR_FICHERO_OK;
}

int leer_int_fichero()
{
    int num;
    FILE *f = fichero_global;

    if (f == NULL) return -1;

    num = 0;
    if (fscanf(f, "%d", &num) != 1) {
        return 0;
    }
    return num;
}

char leer_char_fichero()
{
    FILE *f = fichero_global;
    int ch;

    if (f == NULL) return (char)-1;

    ch = fgetc(f);
    return (char)ch;
}

int es_fin_de_fichero()
{
    FILE *f = fichero_global;
    if (f == NULL) return 1;
    return feof(f);
}

void cerrar_fichero()
{
    FILE *f = fichero_global;
    if (f != NULL) fclose(f);
    fichero_global = NULL;
}

