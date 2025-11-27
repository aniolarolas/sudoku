#include <stdio.h>
#include "colores.h"

int main() {
	int i;

	printf("TEST COLORES\n");
	printf("Invocando a printf_color_negrita():\n");
	printf_color_negrita();
	printf("TEXTO EN NEGRITA\n");
	printf("Invocando a printf_reset_color():\n");
	printf_reset_color();
	printf("TEXTO EN COLOR POR DEFECTO\n");
	printf("Invocando printf_color_num con los siguientes argumentos:\n");
	for (i = 0; i < 14; i++) {
		printf_color_num(i);
		printf("%d ", i);
	}
	printf("\n");
	printf_reset_color();
	printf("Y, volvemos al color por defecto antes de cerrar el main.\n");
}

