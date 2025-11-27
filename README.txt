JUEGA
=====
https://sudoku.com/
https://sudoku4me.com/

RECOMPILAR TESTERS
==================

gcc -o test_ficheros fichero.c test_ficheros.c
gcc -o test_colores colores.c test_colores.c

1 SUDOKU DE CADA TAMAÑO CON SU SOLUCION
=======================================
- z??.txt	Sudoku de tamaño ??.
- z??sol.txt	Y su correspondiente solución.
( Tamaños: 0x0, 1x1, 4x4, 9x9, 16x16, 25x25 y 36x36 )

POSIBLES VALORES EN CADA CASILLA
================================
04x04: 1..4
09x09: 1..9
16x16: 0..9 A..F
25x25: 0..9 A..O
36x36: 0..9 A..Z

COLECCION DE SUDOKUS
====================
- zbaby??.txt	20 Sudokus de 4x4. Muy fáciles.
- zeasy??.txt	20 Sudokus de 9x9. Nivel fácil.
- zfair??.txt	20 Sudokus de 9x9. Nivel medio.
- zhard??.txt	20 Sudokus de 9x9. Nivel difícil.
- zvery??.txt	20 Sudokus de 9x9. Nivel muy difícil.
- zxtrm16??.txt	10 sudokus de 16x16. Ordenados por dificultad del 01 al 10.
- zxtrm25??.txt	10 sudokus de 25x25. Ordenados por dificultad del 01 al 10.
- zxtrm36??.txt	10 sudokus de 36x36. Ordenados por dificultad del 01 al 10.

BASE
====
- Que funcione con 4x4 y/o 9x9.

EXTRAS
======
- Que use el mismo código para 4x4 y 9x9.
	(la función para saber si el sudoku está resuelto, imprimirlo, etc
	tiene que ser la misma;
	con ese 4 o 9 como parámetro o campo del sudoku).
- Luego como extra se puede ampliar para que funcione con sudokus de:
	16x16, 25x25 y 36x36.
	(Para que el algoritmo de saber si está resuelto siga siendo el mismo,
	se puede pasar '1'..'9'  a 1..9, 'A'..'Z' a 10..35,
	y '0' al tamaño del sudoku (16, 25 o 36)).

