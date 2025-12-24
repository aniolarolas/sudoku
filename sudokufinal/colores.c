// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BOLD    "\x1b[1m"
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

void printf_color_num(int num) {
	switch (num % 14) {
		case  0: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_WHITE  ); break;
		case  1: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_RED    ); break;
		case  2: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_GREEN  ); break;
		case  3: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_YELLOW ); break;
		case  4: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_BLUE   ); break;
		case  5: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_MAGENTA); break;
		case  6: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_CYAN   ); break;
		case  7: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_WHITE  ); break;
		case  8: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_RED    ); break;
		case  9: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_GREEN  ); break;
		case 10: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_YELLOW ); break;
		case 11: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_BLUE   ); break;
		case 12: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_MAGENTA); break;
		case 13: printf(ANSI_COLOR_RESET);   printf(ANSI_COLOR_CYAN   ); break;
	}
}

void printf_reset_color() {
	printf(ANSI_COLOR_RESET);
}

void printf_color_negrita() {
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BOLD);
}

