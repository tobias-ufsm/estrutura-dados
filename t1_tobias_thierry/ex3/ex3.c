#include <stdio.h>
#include <stdlib.h>
#include "exc3.h"


typedef struct lista Lista;


typedef struct esparsa Esparsa;


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

// Função para verificar se a matriz é uma matriz identidade
int verificaIdentidade(Esparsa *matrizEsparsa)
{
    Lista *elemento = matrizEsparsa->prim;
    int identidade = 1; // Comece supondo que é uma matriz identidade

    while (elemento != NULL)
    {
        if (elemento->linha != elemento->coluna)
        {
            if(elemento->info != 0){
            printf("Elemento [%d][%d] = %d viola a regra da matriz identidade.\n", elemento->linha, elemento->coluna, elemento->info);
            identidade = 0; // Marque que não é uma matriz identidade
            }            
        }
        else if (elemento->info != 1)
        {
            printf("Elemento [%d][%d] = %d viola a regra da matriz identidade.\n", elemento->linha, elemento->coluna, elemento->info);
        }
        elemento = elemento->prox;
    }

    for(int i = 0; i < matrizEsparsa->colunas; i++){
        int found = 0;
        Lista *elemento = matrizEsparsa->prim;
        while (elemento != NULL)
        {
            if (elemento->linha == i && elemento->coluna == i)
            {
                found = 1;
                break;
            }
            elemento = elemento->prox;
        }
        if(!found){
            printf("Elemento [%d][%d] = %d viola a regra da matriz identidade.\n", i, i, 0);
            identidade = 0;
        }
    }
    return identidade;
}

void imprimirMatriz(Esparsa *matrizEsparsa)
{
    int i, j;
    Lista *elemento = matrizEsparsa->prim;

    // Crie uma matriz temporária para armazenar os elementos
    int **matrizTemp = (int **)malloc(matrizEsparsa->linhas * sizeof(int *));
    for (i = 0; i < matrizEsparsa->linhas; i++)
    {
        matrizTemp[i] = (int *)malloc(matrizEsparsa->colunas * sizeof(int));
        for (j = 0; j < matrizEsparsa->colunas; j++)
        {
            matrizTemp[i][j] = 0;
        }
    }

    // Preencha a matriz temporária com os elementos da lista
    while (elemento != NULL)
    {
        matrizTemp[elemento->linha][elemento->coluna] = elemento->info;
        elemento = elemento->prox;
    }

    // Imprima a matriz
    printf("Matriz esparsa:\n");
    for (i = 0; i < matrizEsparsa->linhas; i++)
    {
        for (j = 0; j < matrizEsparsa->colunas; j++)
        {
            printf("%d ", matrizTemp[i][j]);
        }
        printf("\n");
    }

    // Libere a memória alocada para a matriz temporária
    for (i = 0; i < matrizEsparsa->linhas; i++)
    {
        free(matrizTemp[i]);
    }
    free(matrizTemp);
}