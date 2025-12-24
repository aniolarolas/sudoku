// Este fichero se le da al alumno
#ifndef FICHERO_H
#define FICHERO_H

#include <stdio.h>

#define SIZE_NOMBRE_FICHERO	  80
#define ABRIR_FICHERO_OK	0
#define ABRIR_FICHERO_ERR	-1

int abrir_fichero(char nombre_fichero[]);
int leer_int_fichero();
char leer_char_fichero();
int es_fin_de_fichero();
void cerrar_fichero();

#endif // FICHERO_H

