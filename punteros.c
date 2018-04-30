int main (void) {
	int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
	int *ptr;
	int (*ptr2vector)[4]; /* ptr2vector es un  puntero a un arreglo de 4 enteros */
	int fila, col;
	for (fila = 0; fila < 3; fila++){
			for (col = 0; col < columnas; col++)
				printf("%d  ", *(*(matriz + fila) + col)); /* uso: matriz [fila] [columna] equivalente a *(*(matriz + fila) +j) */
			printf("\n"); /* pasa al renglon siguiente cada vez que se termina de escribir una fila */
		}
