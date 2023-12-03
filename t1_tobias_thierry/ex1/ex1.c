#include "exc1.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

  
typedef struct lista Lista;


typedef struct esparsa Esparsa;


typedef struct diagonal Diagonal;


Lista *criarElemento(int linha, int coluna, int valor)
{
    Lista *elemento = (Lista *)malloc(sizeof(Lista));
    
    elemento->linha = linha;
    elemento->coluna = coluna;
    elemento->info = valor;
    elemento->prox = NULL;
    return elemento;
}

// Função para adicionar um elemento à lista
void adicionarElemento(Esparsa *matrizEsparsa, int linha, int coluna, int valor)
{
    Lista *elemento = criarElemento(linha, coluna, valor);
    elemento->prox = matrizEsparsa->prim;
    matrizEsparsa->prim = elemento;
}

// Função para extrair a diagonal principal de uma matriz esparsa
Diagonal extrairDiagonalPrincipal(Esparsa *matrizEsparsa)
{
    Diagonal diagonal;
    diagonal.ordem = matrizEsparsa->linhas;
    diagonal.v = (int *)malloc(diagonal.ordem * sizeof(int));
   
    // Inicialize o vetor da diagonal com zeros
    for (int i = 0; i < diagonal.ordem; i++)
    {
        diagonal.v[i] = 0;
    }

    // Preencha o vetor da diagonal com os elementos da matriz esparsa
    Lista *elemento = matrizEsparsa->prim;
    while (elemento != NULL)
    {
        if (elemento->linha == elemento->coluna)
        {
            diagonal.v[elemento->linha] = elemento->info;
        }
        elemento = elemento->prox;
    }

    return diagonal;
}

// Função para imprimir o vetor da diagonal principal
void imprimirDiagonal(Diagonal diagonal)
{
    printf("Diagonal Principal:\n");
    for (int i = 0; i < diagonal.ordem; i++)
    {
        printf("%d ", diagonal.v[i]);
    }
    printf("\n");
}
