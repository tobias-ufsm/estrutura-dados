#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int info;
    struct Lista *prox;
}Lista;

Lista* lst_cria(void)
{
    return NULL;
}
Lista* lst_insere(Lista* l, int i)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l)
{
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d ", p->info);
    }
}
int lst_vazia(Lista *l)
{
    return (l==NULL);
} 

Lista* remove_anterior(Lista *l, int v)
{
    Lista* p = l;
    Lista* ant = NULL;
    while (p->prox!=NULL&&p->prox->info!=v)
    {
        ant=p;
        p=p->prox;
    }
    if (p->prox==NULL)
    {
        return l;
    }
    if(ant==NULL)
    {
        l=p->prox;
    }
    else{
        ant->prox=p->prox;
    }
    free(p);
    return l;
}
int main()
{
    Lista* l;
    l = lst_cria();
    l = lst_insere(l, 45);
    l = lst_insere(l, 23);
    l = lst_insere(l, 17);
    l = lst_insere(l, 12);
    lst_imprime(l);
    l=remove_anterior(l, 35);
    printf("\n");
    lst_imprime(l);
    return 0;
}