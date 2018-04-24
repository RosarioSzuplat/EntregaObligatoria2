#include <stdio.h>
#include <stdlib.h>
#include "proba.h"
#include "errores.h"

int main (void) {
	int valor;
	char cara;
	valor = proba();
	printf("%d\n", valor);
	valor = proba2();
	printf("%d\n", valor);
	cara = moneda();
	printf("%c\n", cara);
	valor = dado();
	switch (valor) {
		case 1: {
			puts("|     |");
			puts("|  *  |");
			puts("|     |");
			break;
		}
		case 2: {
			puts("|    *|");
			puts("|     |");
			puts("|*    |");
			break;
		}
		case 3: {
			puts("|*    |");
			puts("|  *  |");
			puts("|    *|");
			break;		
		}
		case 4: {
			puts("|*   *|");
			puts("|     |");
			puts("|*   *|");
			break;
		}
		case 5: {
			puts("|*   *|");
			puts("|  *  |");
			puts("|*   *|");
			break;
		}
		case 6: {
			puts("|*   *|");
			puts("|*   *|");
			puts("|*   *|");
			break;
		}
		case -1: {
			fprintf(stderr, "%s\n", MSJ_ERROR);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

