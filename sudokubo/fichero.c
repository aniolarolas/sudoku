// Este fichero se le da al alumno
#include <stdio.h>
#include "fichero.h"

// #define DEBUG

FILE *set_or_get_fichero(FILE *f) {
	static FILE *fichero = NULL;

	if (f != NULL) {
		// set
		fichero = f;
	}
	// get
	return fichero;
}

int abrir_fichero(char nombre_fichero[]) {
	set_or_get_fichero(fopen(nombre_fichero, "r"));
	if (set_or_get_fichero(NULL) == NULL) {
		return ABRIR_FICHERO_ERR;
	}
	return ABRIR_FICHERO_OK;
}

int leer_int_fichero() {
	int num, ret_fscanf;

	ret_fscanf = fscanf(set_or_get_fichero(NULL), "%d", &num);
	if (ret_fscanf == EOF) {
		return -1;
	}
	return num;
}

char leer_char_fichero() {
	int ret_fscanf;
	char car;

	ret_fscanf = fscanf(set_or_get_fichero(NULL), "%c", &car);
	if (ret_fscanf == EOF) {
		return -1;
	}
	return car;
}

int es_fin_de_fichero() {
	return feof(set_or_get_fichero(NULL));
}

void cerrar_fichero() {
	fclose(set_or_get_fichero(NULL));
}

