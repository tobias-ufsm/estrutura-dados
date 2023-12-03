#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct esparsa
{
    int linhas;
    int colunas;
    struct lista *prim;
};
typedef struct esparsa Esparsa;

// Função para criar um novo elemento da lista


int main()
{
    Esparsa matrizEsparsa;
    matrizEsparsa.prim = NULL;

    printf("Digite o numero de linhas e colunas da matriz esparsa: ");
    scanf("%d", &matrizEsparsa.linhas);

    matrizEsparsa.colunas = matrizEsparsa.linhas; 

    printf("Digite os elementos da matriz esparsa no formato linha coluna valor (separados por espaco):\n");
    int linha, coluna, valor;
    while (1)
    {
        scanf("%d %d %d", &linha, &coluna, &valor);
        if (linha == -1 || coluna == -1 || valor == -1)
        {
            break; // Termina a entrada de elementos
        }
        adicionarElemento(&matrizEsparsa, linha, coluna, valor);
    }

    // Verifique se a matriz é uma matriz identidade
    int identidade = verificaIdentidade(&matrizEsparsa);

    if (identidade)
    {
        printf("A matriz eh uma matriz identidade.\n");
    }
    else
    {
        printf("A matriz nao eh uma matriz identidade.\n");
    }
    
    imprimirMatriz(&matrizEsparsa);

    Lista *elemento = matrizEsparsa.prim;
    while (elemento != NULL)
    {
        Lista *proximo = elemento->prox;
        free(elemento);
        elemento = proximo;
    }

    return 0;
}
