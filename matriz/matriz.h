#ifndef MATRIZ__H
#define MATRIZ__H
#define COLS 100
#include <stdio.h>
#include <stdlib.h>

float matriz1(const float mat [] [COLS], size_t n_filas);
void matriz2(float mat [] [COLS], size_t n_cols, size_t n_filas, float sumando);
void matriz3(float mat [] [COLS], size_t n_cols, size_t n_filas, float sumando);
void matriz4(float mat [] [COLS], size_t n_cols, size_t n_filas);
int matriz5(const float mat [] [COLS], size_t n_cols, size_t n_filas);
float matriz6(const float mat [] [COLS], size_t n_cols);
void matriz7(const float matA [] [COLS], size_t n_colsA, size_t n_filasA, const float matB [] [COLS], size_t n_colsB, size_t n_filasB, float matC [] [COLS]);
float matriz8(const float mat [] [COLS], size_t n_cols, size_t n_filas);
float matriz9(const float mat [] [COLS], size_t n_cols, size_t n_filas);
float matriz10(const float mat [] [COLS], size_t n_cols, size_t n_filas);

#endif
