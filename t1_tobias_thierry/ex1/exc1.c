#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "exc1.h"



int main()
{
    Esparsa matrizEsparsa;

    matrizEsparsa.prim = NULL;
    printf("Digite o número de linhas da matriz esparsa: ");
    scanf("%d", &matrizEsparsa.linhas);

    matrizEsparsa.colunas = matrizEsparsa.linhas;

    printf("Digite os elementos da matriz esparsa no formato linha coluna valor (separados por espaço):\n");
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

    // Extrai e imprime a diagonal principal
    Diagonal diagonal = extrairDiagonalPrincipal(&matrizEsparsa);
    imprimirDiagonal(diagonal);

    // Libere a memória alocada para a lista esparsa e a diagonal
    Lista *elemento = matrizEsparsa.prim;
    while (elemento != NULL)
    {
        Lista *proximo = elemento->prox;
        free(elemento);
        elemento = proximo;
    }
    free(diagonal.v);

    return 0;
}
