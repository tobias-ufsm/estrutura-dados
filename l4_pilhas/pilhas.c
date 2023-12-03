#include <stdlib.h>
#include <stdio.h>

typedef struct
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
    printf("\n");
}
int lst_vazia(Lista *l)
{
    return (l==NULL);
} 

Lista *lst_pop(Lista *l)
{
    if (lst_vazia(l))
    {
        printf("Lista Vazia\n");
        return;
    }
    Lista* p;
    p=l->prox;
    free(l);
    return p;
}


int main()
{

    Lista* l;
    l = lst_cria();
    l = lst_insere(l, 23);
    lst_imprime(l);
    l = lst_insere(l, 45);
    lst_imprime(l);
    l = lst_insere(l, 89);
    lst_imprime(l);
    l=lst_pop(l);
    lst_imprime(l);
    l=lst_pop(l);
    lst_imprime(l);
    l=lst_pop(l);
    lst_imprime(l);

    l=lst_pop(l);
    return 0;

}