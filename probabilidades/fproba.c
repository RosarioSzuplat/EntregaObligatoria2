#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "proba.h"

int proba (void) {
	int x;
	srand(time(NULL));
	x = rand() % 10;
	if (x == 0 || x == 1) 
		return 0;
	else if (x > 1 && x <= 9)
		return 1;
	else
		return -1;
}

int proba2 (void) {
	int x;
	srand(time(NULL));
	x = rand() % 100;
	if (x >= 0 && x <= 9)
		return 3;
	else if (x >= 10 && x <= 64)
		return 5;
	else if (x >= 65 && x <= 99)
		return 9;
	else
		return -1;
}

char moneda (void) {
	int x;
	srand(time(NULL));
	x = rand() %2;
	if (x == 0)
		return 'H';
	else if (x == 1)
		return 'T';
	else
		return 'X';
}

int dado (void) {
	int x;
	srand(time(NULL));
	x = rand() %6;
	if (x == 0)
		return 1;
	else if (x == 1)
		return 2;
	else if (x == 2)
		return 3;
	else if (x == 3)
		return 4;
	else if (x == 4)
		return 5;
	else if (x == 5)
		return 6;
	else
		return -1;
}

