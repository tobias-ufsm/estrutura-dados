#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex4.h"

int main()
{
    int m, n, z;

    printf("Digite as dimensoes da matriz (m n z): ");
    scanf(" %d %d %d", &m, &n, &z);

    int ***matriz = allocate_matrix_3d(m, n, z);

    fill_matrix_3d(matriz, m, n, z);

    printf("Matriz tridimensional em camadas de profundidade:\n");
    print_matrix_3d(matriz, m, n, z);

    //printf("\nTeste:%d", matriz[1][2][2]);
    desallocate_matrix_3d(matriz, m, n);

    return 0;
}