#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#define COLS 100

float matriz1(const float mat [] [COLS], size_t n_filas) { /*agrego const porque la funcion no modificara a la matriz ingresada */
	float traza = 0;
	int i;
	for (i = 0; i < n_filas; i++) /*solo se sumaran elementos de la diagonal, elementos que tienen numero de fila igual al numero de columna*/
		traza += mat [i] [i];
	return traza;
}

void matriz2(float mat [] [COLS], size_t n_cols, size_t n_filas, float sumando) {
	int i,j;
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++)
		mat [i] [j] += sumando; /* se va sumando el numero indicado a cada componente a medida que se itera */
}

void matriz3(float mat [] [COLS], size_t n_cols, size_t n_filas, float sumando) {
	int i,j;
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++)
		mat [i] [j] *= sumando; /* se va multiplicando el numero indicado a cada componente a medida que se itera */
}

void matriz4(float mat [] [COLS], size_t n_cols, size_t n_filas) {
	int i,j;
	float mat_transpuesta [COLS] [COLS];
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++)
		mat_transpuesta [i] [j] = mat [i] [j]; /* se obtiene la matriz transpuesta */
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++)
		mat [i] [j] = mat_transpuesta [j] [i]; /*se reeemplaza la matriz dad por su transpuesta*/
}

int matriz5(const float mat [] [COLS], size_t n_cols, size_t n_filas) {
	int i,j, neg = 0, no_pos = 0, pos = 0;
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++) {
		if (mat [i] [j] < 0) 
			neg += 1;
		if (mat [i] [j] == 0)
			no_pos +=1;
		if (mat [i] [j] > 0) 
			pos += 1; /*seran distintos de 0 las variables que representen un tipo de numero (positivo, negativo o 0) que se encuentren en la matriz */
	}
	if ((no_pos + pos) == 0 && neg > 0)
		return -2; /* definida negativa */
	if (pos == 0 && no_pos > 0 && neg > 0)
		return -1; /* no negativa */
	if (neg == 0 && no_pos > 0 && pos > 0)
		return 0; /* no positiva */
	if ((neg + no_pos ) == 0 && pos > 0)
		return 1; /* definida positiva */
	else
		return 2;
}

float matriz6(const float mat [] [COLS], size_t n_cols) { /* calculo del determinante */
	if (n_cols == 2)
		return ((mat [0] [0] * mat [1] [1]) - (mat [0] [1] * mat [1] [0]));
	else
		return ((mat [0] [0]*mat [1] [1]*mat [2] [2]) + (mat [0] [1]*mat [1] [2]*mat [2] [0]) + (mat [0] [2]*mat [1] [0]*mat [2] [1]) - (mat [0] [2]*mat [1] [1]*mat [2] [0]) - (mat [0] [1]*mat [1] [0]*mat [2] [2]) - (mat [0] [0]*mat [1] [2]*mat [2] [1]));
}

void matriz7(const float matA [] [COLS], size_t n_colsA, size_t n_filasA, const float matB [] [COLS], size_t n_colsB, size_t n_filasB, float matC [] [COLS]) {
	float suma_productos = 0;
	int i,j,k; /* i=filas de A, j=columnas de A, k=columnas de B */
	for (i = 0; i < n_filasA; i++)
	for (k = 0; k < n_colsB; k++) {
		suma_productos = 0; /*suma se inicializa en 0 para cada fila */
		for (j = 0; j < n_colsA; j++) /*el numero de columna de A es igual al numero de fila de B */
		suma_productos += (matA [i] [j]*matB [j] [k]); /*producto escalar */
	matC [i] [k] = suma_productos;
		}
}

float matriz8(const float mat [] [COLS], size_t n_cols, size_t n_filas) {
	int i,j;
	float max = mat [0] [0];
	for (i = 0; i < n_filas; i++)
	for (j = 0; j < n_cols; j++) {
		if( mat [i] [j] > max)
		max = mat [i] [j]; /*maximo luego de iterar sobre todas las filas PARA CADA columna */
	}
	return max;
}

float matriz9(const float mat [] [COLS], size_t n_cols, size_t n_filas) {
	int i,j;
	float suma = 0, max = 0;
	for (j = 0; j < n_cols; j++) {
		suma = 0;
		for (i = 0; i < n_filas; i++)
			suma += abs (mat [i] [j]);
		if (suma > max)
			max = suma; /*maximo luego de iterar sobre todas las filas PARA CADA fila */
	}
	return max;
}

float matriz10(const float mat [] [COLS], size_t n_cols, size_t n_filas) {
	int i,j;
	float suma = 0, max = 0;
	for (i = 0; i < n_filas; i++) {
	suma = 0; /* se inicializa en 0 para cada iteracion */
	for (j = 0; j < n_cols; j++)
		suma += abs (mat [i] [j]); /* se toma valor absoluto */
		if (suma > max)
			max = suma;
	}
	return max;
}




