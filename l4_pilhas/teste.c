#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;
struct pilha
{
    Lista *prim; /* aponta para o topo da pilha */
};
typedef struct pilha Pilha;

Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}
void pilha_push(Pilha *p, float v)
{
    Lista *n = (Lista *)malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}
int pilha_vazia(Pilha *p)
{
    return (p->prim == NULL);
}
float pilha_pop(Pilha *p)
{
    Lista *t;
    float v;
    if (pilha_vazia(p))
    {
        printf("*** Pilha vazia.\n");
        system("pause");
        exit(1);
    } /* aborta programa */
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}
void pilha_libera(Pilha *p)
{
    Lista *q = p->prim;
    while (q != NULL)
    {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}
void pilha_imprime(Pilha *p)
{
    Lista *q;
    if (!pilha_vazia(p))
        for (q = p->prim; q != NULL; q = q->prox)
            printf("\n\t Lista: %.2f\n", q->info);
    else
        printf("\nNao ha como imprimir a pilha, pois esta vazia\n");
}
void concatena_pilhas(Pilha *p1, Pilha *p2)
{
    Pilha *p3;
    p3 = pilha_cria();
    while (!pilha_vazia(p2))
        pilha_push(p3, pilha_pop(p2));
    printf("\n pilha 3: ");
    pilha_imprime(p3);
    while (!pilha_vazia(p3))
        pilha_push(p1, pilha_pop(p3));
}

int main()
{
    Pilha *p1;
    Pilha *p2;
    p1 = pilha_cria();
    p2 = pilha_cria();
    printf("\nInserindo na pilha 1....\n");
    pilha_push(p1, 1);
    pilha_push(p1, 4.5);
    pilha_push(p1, 2.1);
    pilha_imprime(p1);
    printf("\nInserindo na pilha 2\n");
    pilha_push(p2, 9.8);
    pilha_push(p2, 3.1);
    pilha_push(p2, 7.2);
    pilha_imprime(p2);
    concatena_pilhas(p1, p2);
    printf("\nApos: pilha 1: ");
    pilha_imprime(p1);
    printf("\nApos: pilha 2: ");
    pilha_imprime(p2);
    pilha_libera(p1);
    pilha_libera(p2);
    system("PAUSE");
    return 1;
}
