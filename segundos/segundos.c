#include <stdio.h>
#include <stdlib.h>
#include "errores.h"
#include "segundos.h"
#define MSJ_INGRESO_SEGUNDOS "Ingrese la cantidad de segundos"

int main (void) {
	int validacion, *horas_ptr = NULL, *minutos_ptr = NULL, horas, minutos;
	long int *segundos_ptr = NULL, segundos;
	int c;
	
	puts(MSJ_INGRESO_SEGUNDOS);
	validacion = scanf("%ld", &segundos);
	if (validacion != 1) {
		fprintf(stderr,"%s: %s\n", MSJ_ERROR, MSJ_NUMERO_INVALIDO);
		return EXIT_FAILURE;
	}
	while ((c = getchar ()) != '\n' && c != EOF) /* se obtiene cantidad de sengundos a convertir */
		;
	segundos_ptr = &segundos;
	minutos_ptr = &minutos;
	horas_ptr = &horas; /* se asignan variables a las direcciones de memoria para que tenga sentifo utilizarlas */
	if ((convertir (segundos_ptr, minutos_ptr, horas_ptr)) == ST_ERROR_NEGATIVO) {
		fprintf(stderr,"%s: %s", MSJ_ERROR, MSJ_NEGATIVO);
		return EXIT_FAILURE; /*validacion par que no se devuelvan magnitudes de tiempo negativas */
	}
	if ((convertir (segundos_ptr, minutos_ptr, horas_ptr)) == ST_OK) /*se convierte */
		printf("La magnitud equivale a %d horas, %d minutos, %ld segundos\n", *horas_ptr, *minutos_ptr, *segundos_ptr);
	return EXIT_SUCCESS;
}
