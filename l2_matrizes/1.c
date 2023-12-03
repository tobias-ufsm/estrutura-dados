#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
int main()
{
    int l = 2;
    int c = 3;

    int **matriz = (int **)allocate_matrix(l, c, sizeof(int));
    fill_matrix(matriz, l, c, sizeof(int));
    print_matrix(matriz, l, c, sizeof(int));


    printf("\n\n%d\n\n", matriz[1][2]);


    // Liberar a memória alocada
    for (int i = 0; i < l; i++)     
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}