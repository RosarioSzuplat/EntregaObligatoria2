#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "errores.h"
#include "matriz.h"
#define COLS 100
#define PEDIR_DIMENSION "Ingrese primero la cantidad de filas y luego la de columnas"
#define PEDIR_COEFICIENTES "Ingrese los coeficientes de la matriz"
#define MAX_COLS "Cantidad de filas o columnas demasiado grande"
#define PREGUNTAR_2 "Desea sumarle un  numero a cada coeficiente de su matriz? [S/N]"
#define PEDIR_NUMERO "Ingrese el numero"
#define PREGUNTAR_3 "Desea multiplicar cada coeficiente por un numero? [S/N]"
#define PREGUNTAR_4 "Desea trasponer la funcion? [S/N]"
#define NEG "La matriz es negativa."
#define POS "La matriz es positiva."
#define NO_NEG "La matriz es no negativa."
#define NO_POS "La matriz es no positiva."
#define NO_CLASIFIC "La matriz no puede clasificarse como positiva ni negativa ni no positiva ni no negativa."
#define PREGUNTAR_5 "Desea calcular determinante de funcion de 2x2 o 3x3? [S/N]"
#define INGRESE_MATRIZ_DETERMINANTE "Ingrese matriz de 3x3 o 2x2 para calcular determinante."
#define PEDIR_MATRIZ "Ingrese matriz para multiplicar a la matriz inicial"
#define INGRESE_MATRIZ_PRODUCTO "Ingrese matriz para multiplicar por la matriz ingresada al comienzo"

int main (void) {
	float mat [COLS] [COLS], mat_B [COLS] [COLS], mat_C [COLS] [COLS];
	float traza_matriz, numero, determinante, maximo, norma_1, norma_infinito;
	int i, j, validacion, filas, columnas, clasific, columnas_B, filas_B;
	char c, respuesta;
	do {
		puts(PEDIR_DIMENSION);
		validacion = scanf("%d %d", &filas, &columnas);
		if (validacion != 2) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (filas <= 0 || columnas <= 0) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NO_LOGICO);
			return EXIT_FAILURE;
		}
		if (filas > COLS || columnas > COLS)
			puts(MAX_COLS);
	}
		while (filas > COLS || columnas > COLS); /* se obtiene dimensiones de la matriz */
	puts(PEDIR_COEFICIENTES);
	for (i = 0; i < filas; i++)
	for (j = 0; j < columnas; j++) {
		validacion = scanf("%f", & mat [i] [j]);
		if (validacion != 1) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF) /*se obtienen coeficientes */
			;
	}
	if (filas == columnas) {		/* solo tiene sentido calcular la traza en matrices cuadradas */
		traza_matriz = matriz1((const float (*)[COLS])mat, filas);
		printf("La traza de la matriz es %f\n", traza_matriz);
	}

	maximo = matriz8((const float (*)[COLS])mat, columnas, filas); /*elemnto maximo */
	printf("El maximo elemento de la matriz es %.3f\n", maximo);

	norma_1 = matriz9((const float (*)[COLS])mat, columnas, filas); /*norma 1 */
	printf("La norma uno de la matriz es %.3f \n", norma_1);

	norma_infinito = matriz10((const float (*)[COLS])mat, columnas, filas); /*norma infinito */
	printf("La norma infinito de la matriz es %.3f \n", norma_infinito);

	puts(INGRESE_MATRIZ_PRODUCTO);
	do {
		puts(PEDIR_DIMENSION);
		validacion = scanf("%d %d", &filas_B, &columnas_B);
		if (validacion != 2) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (filas_B <= 0 || columnas_B <= 0) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NO_LOGICO);
			return EXIT_FAILURE;
		}
		if (filas_B > COLS || columnas_B > COLS)
			puts(MAX_COLS);
		if (filas_B != columnas) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_DIMENSION);
			return EXIT_FAILURE;
		}
	}
		while (filas > COLS || columnas_B > COLS); /*se obtiene dimension de la matriz a multiplicar */

	puts(PEDIR_COEFICIENTES);
	for (i = 0; i < filas_B; i++)
	for (j = 0; j < columnas_B; j++) {
		validacion = scanf("%f", & mat_B [i] [j]);
		if (validacion != 1) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF) /* se cargan sus coeficientes */
			;
	}
	matriz7((const float (*)[COLS])mat, columnas, filas, (const float (*)[COLS])mat_B, columnas_B, filas_B, (float (*)[COLS])mat_C);
	for (i = 0; i < filas; i++){
			for (j = 0; j < columnas; j++)
				printf("%.2f  ", mat_C [i] [j]);
			printf("\n"); /* se imprime producto en forato tabular */
		}

	puts(PREGUNTAR_2);
	respuesta = getchar();
	if (toupper(respuesta) == 'S') {
		puts(PEDIR_NUMERO);
		scanf("%f", &numero);
		matriz2((float (*)[COLS])mat, columnas, filas, numero); /* se obtiene matriz con coeficientes modificados: se les sumo el numero indicado*/
		for (i = 0; i < filas; i++){
			for (j = 0; j < columnas; j++)
				printf("%.2f  ", mat [i] [j]);
			printf("\n");
		}
	}
	else if (toupper(respuesta) != 'N') {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_RESPUESTA_INVALIDA);
		return EXIT_FAILURE;
	}
	
	while ((c=getchar ()) != '\n') /* limpio buffer, sino no me deja seguir ingresando valores en la terminal*/
		;
	puts(PREGUNTAR_3);
	respuesta = getchar();
	if (toupper(respuesta) == 'S') {
		puts(PEDIR_NUMERO);
		scanf("%f", &numero);
		matriz3((float (*)[COLS])mat, columnas, filas, numero);
		for (i = 0; i < filas; i++){
			for (j = 0; j < columnas; j++)
				printf("%.2f  ", mat [i] [j]); /* se obtiene matriz con coeficientes modificados: se les multiplico el numero indicado*/
			printf("\n");
		}
	}
	else if (toupper(respuesta) != 'N') {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_RESPUESTA_INVALIDA);
		return EXIT_FAILURE;
	}
	while ((c=getchar ()) != '\n')
		;
	puts(PREGUNTAR_4);
	respuesta = getchar();
	if (toupper(respuesta) == 'S') {
		matriz4((float (*)[COLS])mat, columnas, filas); /* es mas eficiente imprimir directamente, luego del ciclo, mat [j] [i] pero se pide hacerlo con una funcion*/
		for (i = 0; i < filas; i++){
			for (j = 0; j < columnas; j++)
				printf("%.2f  ", mat [i] [j]);
			printf("\n"); /* se imprime transpuesta */
		}
	}
	else if (toupper(respuesta) != 'N') {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_RESPUESTA_INVALIDA);
		return EXIT_FAILURE;
	}
	clasific = matriz5((const float (*)[COLS])mat, columnas, filas); /*clasificacion en positiva, no positiva, negativa y no negativa */
	switch (clasific) {
		case -2:
			puts(NEG);
			break;
		case -1:
			puts(NO_NEG);
			break;
		case 0:
			puts(NO_POS);
			break;
		case 1:
			puts(POS);
			break;
		case 2:
			puts(NO_CLASIFIC);
			break;
		default: {
			fprintf(stderr, "%s\n", MSJ_ERROR);
			return EXIT_FAILURE;
		}
	}
	while ((c=getchar ()) != '\n') /* limpio buffer*/
		;
	puts(PREGUNTAR_5); /* calculo determinante */
	respuesta = getchar();
	if (toupper(respuesta) == 'S') {
	puts(INGRESE_MATRIZ_DETERMINANTE);
	do {
		puts(PEDIR_DIMENSION); 
		validacion = scanf("%d %d", &filas, &columnas);
		if (validacion != 2) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF)
			;
		if (filas <= 0 || columnas <= 0) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NO_LOGICO);
			return EXIT_FAILURE;
		}
		if (filas > COLS || columnas > COLS)
			puts(MAX_COLS);
		if (filas != columnas) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_CUADRADA);
			return EXIT_FAILURE;
		}
	}
		while (filas > COLS || columnas > COLS); /* se obtiene dimension */
	puts(PEDIR_COEFICIENTES);
	for (i = 0; i < filas; i++)
	for (j = 0; j < columnas; j++) {
		validacion = scanf("%f", & mat [i] [j]);
		if (validacion != 1) {
			fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
			return EXIT_FAILURE;
		}
		while ((c = getchar()) != '\n' && c != EOF) /* se obtienen coeficientes */
			;
	}
	determinante = matriz6((const float (*)[COLS])mat, columnas);
	printf("El determinante es : %f\n", determinante); /* calculo determinante */
	}
	else if (toupper(respuesta) != 'N') {
		fprintf(stderr, "%s: %s\n", MSJ_ERROR, MSJ_RESPUESTA_INVALIDA);
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
