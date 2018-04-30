#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
	int * ptr; /*no lo uso*/
	int (*ptr2vector)[4]; /*puntero a un arreglo de 4 enteros, entonces apuntara a cada fila de la matriz*/
	int fila, col;
	ptr2vector = matriz;
	for (fila = 0; fila < 3; fila ++) {
		for (col = 0; col < 4; col ++) 
			printf("%d  ", *(*(ptr2vector + fila) + col));/*matriz [i] [j]*/
		printf("\n");
	}
	return EXIT_SUCCESS;
}
