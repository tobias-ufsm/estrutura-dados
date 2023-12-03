#define _matriz_h_

#include <stdio.h>



void **allocate_matrix(int rows, int columns, size_t size_type);
void fill_matrix(void **matrix, int rows, int columns, size_t size_type);
void print_matrix(void **matrix, int rows, int columns, size_t size_type);

