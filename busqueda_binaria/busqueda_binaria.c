#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define PEDIDO_OBJETIVO "Introduzca el numero a buscar"
#include "busqueda_binaria.h"
#include "errores.h"

int main (void) {
	int v [SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	char c;
	int posicion, validacion, objetivo;
	puts(PEDIDO_OBJETIVO);
	validacion = scanf("%d", &objetivo);
	if (validacion != 1) {
		fprintf(stderr,"%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
		return EXIT_FAILURE;
	}
	while ((c = getchar ()) != '\n' && c != EOF)
		;
	posicion = busqueda_binaria (v, SIZE, objetivo, 0, SIZE -1);
	if (posicion == -1)
	printf ("El numero %d no se encuentra en niguna componente del vector.\n", objetivo);
	else if (posicion == -1)
	printf ("El numero %d no se encuentra en niguna componente del vector.\n", objetivo);
	else
	printf ("%d se encuentra en la posicion %d del vector.\n", objetivo, posicion);
	return EXIT_SUCCESS;
}
