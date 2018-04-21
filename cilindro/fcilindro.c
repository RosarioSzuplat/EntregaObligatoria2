#include "cilindro.h"

float diametro (float r, float h) {
	if (r < 0)
	return -1;
	return 2*r;
}
float circunferencia (float r, float h) {
	if (r < 0)
	return -1;
	return 2*PI*r;
}
float base (float r, float h) {
	if (r < 0)
	return -1;
	return PI*r*r;
}
float volumen (float r, float h) {
	if (r < 0 || h < 0)
	return -1;
	return PI*r*r*h;
}
