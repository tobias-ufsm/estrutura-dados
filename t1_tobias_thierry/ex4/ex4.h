#define _exc4_h_

#include <stdio.h>

void **allocate_matrix(int rows, int columns, size_t size_type);
void fill_matrix(void **matrix, int rows, int columns, size_t size_type);
void print_matrix(void **matrix, int rows, int columns, size_t size_type);

int ***allocate_matrix_3d(int rows, int columns, int depth);
void fill_matrix_3d(int ***matrix, int rows, int columns, int depth);
void print_matrix_3d(int ***matrix, int rows, int columns, int depth);
void desallocate_matrix_3d(int ***matrix, int rows, int columns);