#include <stdio.h>
#include <stdlib.h>

// Definição da struct para a matriz diagonal
struct diagonal
{
    int ordem; // ordem da matriz
    int *v;    // vetor que armazena os elementos da diagonal principal
};

typedef struct diagonal Diagonal;

Diagonal criar_matriz_diagonal(int ordem)
{
    Diagonal matriz;
    matriz.ordem = ordem;
    matriz.v = (int *)malloc(ordem * sizeof(int));
    return matriz;
}

void preencher_matriz(Diagonal *matriz)
{
    int i;
    int num;
    for (i = 0; i < matriz->ordem; i++)
    {
        printf("Insira o elemento da diagonal [%d][%d]: ", i, i);
        scanf(" %d", &num);
        matriz->v[i] = num;
    }
}

void imprimir_matriz(Diagonal matriz)
{
    int i, j;
    for (i = 0; i < matriz.ordem; i++)
    {
        for (j = 0; j < matriz.ordem; j++)
        {
            if (i == j)
            {
                printf("%d ", matriz.v[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int consultar_elemento(Diagonal matriz, int linha, int coluna)
{
    if (linha < 0 || linha >= matriz.ordem || coluna < 0 || coluna >= matriz.ordem)
    {
        printf("Posicao fora dos limites da matriz\n");
        return -1;
    }

    if (linha == coluna)
    {
        return matriz.v[linha];
    }
    else
    {
        return 0;
    }
}

int main()
{
    int ordem;
    printf("Digite a ordem da matriz diagonal: ");
    scanf(" %d", &ordem);

    Diagonal matriz = criar_matriz_diagonal(ordem);
    preencher_matriz(&matriz);

    printf("Matriz diagonal:\n");
    imprimir_matriz(matriz);

    int linha, coluna;
    printf("Digite a linha e a coluna para consultar um elemento: ");
    scanf(" %d %d", &linha, &coluna);

    int elemento = consultar_elemento(matriz, linha, coluna);
    if (elemento != -1)
    {
        printf("Elemento na posicao [%d][%d]: %d\n", linha, coluna, elemento);
    }

    free(matriz.v);
    return 0;
}
