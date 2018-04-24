#include <stdio.h>
#include "segundos.h"

status_t convertir(long int *segundos, int *minutos, int *horas) {
	if (*segundos < 0)
	return ST_ERROR_NEGATIVO; /* funcion devuelve error */
	else {
		*horas = (*segundos)/3600; /*calculo de horas, minutos y segundos */
		*minutos = (*segundos % 3600)/60; /*se modifican directamente los valores guardados en las varaibles en las direcciones de memoria */
		*segundos = (*segundos % 3600) % 60;
		return ST_OK; /*funcion devuelve que no hubo errores*/
	}
}
