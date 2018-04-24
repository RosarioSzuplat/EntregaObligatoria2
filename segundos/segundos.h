#ifndef SEGUNDOS__H
#define SEGUNDOS__H
#include <stdio.h>


typedef enum {ST_OK,
	      ST_ERROR_NEGATIVO
	      } status_t;
status_t convertir(long int *segundos, int *minutos, int *horas);

#endif
