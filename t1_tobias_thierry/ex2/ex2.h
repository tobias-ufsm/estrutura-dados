#define _ex2_h_

#include <stdio.h>

typedef struct Lista
{
    int info;
    int row;
    int column;
    struct Lista *prox;
} Lista;

typedef struct Esparsa
{
    int rows;
    int columns;
    struct Lista *prox;
} Esparsa;

Lista *lst_cria(void);
Lista *lst_insere(Lista *l, int i, int rows, int columns);

void preenche_matriz_esparsa(Esparsa *matriz);
void imprime_matriz_esparsa(Esparsa *matriz);

int busca_elemento(Esparsa *matriz, int linha, int coluna);
int somatorio_linha(Esparsa *matriz, int linha);
float percentual_nao_nulos(Esparsa *matriz);