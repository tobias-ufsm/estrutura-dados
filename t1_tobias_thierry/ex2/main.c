#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex2.h"

int main()
{
    srand(time(NULL));

    Esparsa espar;
    espar.prox = lst_cria();

    printf("Digite a quantidade de linhas e colunas para a construcao da matriz: ");
    scanf(" %d %d", &espar.rows, &espar.columns);
    printf("\n");

    preenche_matriz_esparsa(&espar);
    imprime_matriz_esparsa(&espar);

    int l, c;

    printf("\nDigite a linha e a coluna do elemento a ser buscado iniciando em 0 e indo ate linha %d e coluna %d:\n", espar.rows-1, espar.columns-1);
    scanf("%d %d", &l, &c);
    printf("\nElemento linha '%d' e coluna '%d' = %d\n", l, c, busca_elemento(&espar, l, c));

    printf("Insira a uma linha para realizar o somatorio de seus elementos: ");
    scanf("%d", &l);
    printf("Somatorio da linha '%d': %d\n", l, somatorio_linha(&espar, l));

    printf("\nPercentual de elementos nao nulos: %.2f%%\n", percentual_nao_nulos(&espar));
}