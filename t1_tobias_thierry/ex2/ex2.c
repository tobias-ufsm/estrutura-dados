#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex2.h"

Lista *lst_cria(void)
{
    return NULL;
}
Lista *lst_insere(Lista *l, int i, int rows, int columns)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = i;
    novo->row = rows;
    novo->column = columns;
    novo->prox = NULL;

    if (l == NULL)
    {
        return novo;
    }
    else
    {
        Lista *p = l;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo;
        return l;
    }
}

void preenche_matriz_esparsa(Esparsa *matriz)
{
    for (int i = 0; i < matriz->rows; i++)
    {
        for (int j = 0; j < matriz->columns; j++)
        {
            int num = rand() % 8;
            if (num != 0)
            {
                matriz->prox = lst_insere(matriz->prox, num, i, j);
            }
        }
    }
}
void imprime_matriz_esparsa(Esparsa *matriz)
{
    for (int i = 0; i < matriz->rows; i++)
    {
        for (int j = 0; j < matriz->columns; j++)
        {
            Lista *p = matriz->prox;
            int found = 0;
            while (p != NULL)
            {
                if (p->row == i && p->column == j)
                {
                    printf("%d ", p->info);
                    found = 1;
                    break;
                }
                p = p->prox;
            }
            if (!found)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int busca_elemento(Esparsa *matriz, int linha, int coluna)
{
    Lista *p = matriz->prox;
    while (p != NULL)
    {
        if (p->row == linha && p->column == coluna)
        {
            return p->info;
        }
        p = p->prox;
    }
    return 0;
}
int somatorio_linha(Esparsa *matriz, int linha)
{
    int somatorio = 0;
    Lista *p = matriz->prox;
    while (p != NULL)
    {
        if (p->row == linha)
        {
            somatorio += p->info;
        }
        p = p->prox;
    }
    return somatorio;
}
float percentual_nao_nulos(Esparsa *matriz)
{
    int nao_nulos = 0;
    Lista *p = matriz->prox;
    while (p != NULL)
    {
        nao_nulos++;
        p = p->prox;
    }

    int total = matriz->rows * matriz->columns;
    float percentual = (float)nao_nulos / total * 100.0;
    return percentual;
}
