// Este fichero se le da al alumno
#include <stdio.h>
#include "fichero.h"

#define SIZE_NOMBRE_FICHERO	  80

int main() {
	int err, f, c, size, car;
	char nombre_fichero[SIZE_NOMBRE_FICHERO];

	printf("Introduce el nombre del fichero: ");
	scanf("%s%*c", nombre_fichero);
	err = abrir_fichero(nombre_fichero);
	if (err != ABRIR_FICHERO_OK) {
		printf("ERROR: FICHERO NO ENCONTRADO.\n");
		printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
	} else {
		size = leer_int_fichero();
		leer_char_fichero(); // '\n'
		printf("Sudoku %dx%d\n\n",
			       size, size);
		for (f = 0; f < size; f++) {
			for (c = 0; c < size; c++) {
				car = leer_char_fichero();
				printf("%c ", car);
			}
			leer_char_fichero(); // '\n'
			printf("\n");
		}
		cerrar_fichero();
	}
}

