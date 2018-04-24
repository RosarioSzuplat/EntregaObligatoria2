#include <stdio.h>
#include "busqueda_binaria.h"

int busqueda_binaria(const int v[], /* vector donde buscar ORDENADO de menor a mayor */
                      size_t n,      /* largo del vector */
                      int objetivo,  /* elemento a buscar */
                      size_t izq,    /* franja del vector donde buscar, */
                      size_t der) {   /* delimitada por izq y der */

	size_t medio;
	while (izq <= der) {
		medio = (der + izq)/2;
		if (objetivo == v [medio]) { /* si encuentra el valor del objetivo, lo devuelve */
			return medio;
		}
		else if (objetivo < v [medio]) /* si el objetivo es menor al valor de la mitad del arreglo, se pasa a buscar solo en la primera mitad */
			der = medio - 1;
		else
			izq = medio + 1; /* si el objetivo es mayor, en la segunda mitad */
	}
	return -1; /* devuelve posicion incoherente en el caso de que el objetivo no sea encontrado en el vector */
}
