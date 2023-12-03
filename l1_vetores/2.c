#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int negativos(int n, int *vet)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    int n;
    scanf(" %d", &n);
    int *v;
    v = (int *)malloc(n * sizeof(int));

    if (v == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1); /* aborta o programa e retorna 1 para o sist. operacional */
    }
    else
    {
        for (int i = -5; i < 5; i++)
        {
            v[i + 5] = i;
        }

        printf(" %d", negativos(n, v));
    }
    free(v);
}