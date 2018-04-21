#include <stdio.h>
#include <stdlib.h>
#include "errores.h"
#define PEDIR_TEMPERATURA "Ingrese la temperatura de la clase espectral en grados Kelvin"
#define TEMP_MAX 50000
#define TEMP_MIN 1700

typedef enum {O, B ,A, F, G, K, M} clase_espectral;

int main (void) {
	long int temp;
	int validacion;
	char c;
	clase_espectral clase;

	puts(PEDIR_TEMPERATURA);
	validacion = scanf("%ld", &temp);
	if (validacion != 1) {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
		return EXIT_FAILURE;
	}
	while ((c = getchar()) != '\n' && c != EOF)
		;
	if (temp < TEMP_MIN || temp > TEMP_MAX) {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NO_LOGICO);
		return EXIT_FAILURE;
	}
	if (temp >= 28000 && temp <= 50000)
		clase = O;
	if (temp >= 9600 && temp < 28000)
		clase = B;
	if (temp >= 7100 && temp < 9600)
		clase = A;
	if (temp >= 5700 && temp < 7100)
		clase = F;
	if (temp >= 4600 && temp < 5700)
		clase = G;
	if (temp >= 3200 && temp < 4600)
		clase = K;
	if (temp >= 1700 && temp < 3200)
		clase = M;
	switch (clase) {
	case O :
		puts("Azul");
		break;
	case B :
		puts("Blanco azulado");
		break;
	case A :
		puts("Blanco");
		break;
	case F :
		puts("Blanco amarillento");
		break;
	case G :
		puts("Amarillo");
		break;
	case K :
		puts("Naranja");
		break;
	case M :
		puts("Rojo");
		break;
	default : {
		fprintf(stderr, "%s\n", MSJ_ERROR);
		return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
