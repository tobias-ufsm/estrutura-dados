#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inverte(int n, int *v)
{
    int aux, metade;
    if (n%2==0)
    {
        metade=n/2;
    }
    else
    {
        metade=n/2+1;
    }
    for (int i = 0; i < metade; i++)
    {
        aux=v[i];
        v[i]=v[n-(i+1)];
        v[n-(i+1)]=aux;
    }
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
        for (int i = 0; i < n; i++)
        {
            printf(" %d", v[i]);
        }
        printf("\n");
        inverte(n, v);
        for (int i = 0; i < n; i++)
        {
            printf(" %d", v[i]);
        }
        
    }
    free(v);
}