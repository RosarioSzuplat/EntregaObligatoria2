#include <stdlib.h>
#include <stdio.h>
#include "cilindro.h"
#include "errores.h"
#define MSJ_INGRESO "Ingrese el radio y la altura del cilindro"
int main (void) {
	float r, h;
	int validacion;
	char c;
	puts(MSJ_INGRESO);
	validacion = scanf("%f %f", &r, &h);
	if (validacion != 2) {
		fprintf(stderr, "%s: %s", MSJ_ERROR, MSJ_CARACTER_INVALIDO);
		return EXIT_FAILURE;
	}
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("Diametro: %f\nLongitud circunferencia: %f\nArea base: %f\nVolumen cilindro: %f\n", diametro (r, h), circunferencia (r, h), base (r, h), volumen (r, h));
	return EXIT_SUCCESS;
}
