#include "filas.h"
#include <stdlib.h>
#include <stdio.h>
Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}
void fila_insere(Fila *f, float v)
{
    Lista *n = (Lista *)malloc(sizeof(Lista));
    n->info = v;        /* armazena informação */
    n->prox = NULL;     /* novo nó passa a ser o último */
    if (f->fim != NULL) /* verifica se lista não estava vazia */
        f->fim->prox = n;
    else /* fila estava vazia */
        f->ini = n;
    f->fim = n; /* fila aponta para novo elemento */
}
int fila_vazia(Fila *f)
{
    return (f->ini == NULL);
}
float fila_retira(Fila *f)
{
    Lista *t;
    float v;
    if (fila_vazia(f))
    {
        printf("\nFila vazia. Nao ha como remover elementos\n");
        system("pause");
        exit(1);
    } /* aborta programa */
    printf("\nVai remover o inicio da fila, q neste momento eh o elemento %.2f", f->ini->info);
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL) /* verifica se fila ficou vazia */
        f->fim = NULL;
    free(t);
    return v;
}