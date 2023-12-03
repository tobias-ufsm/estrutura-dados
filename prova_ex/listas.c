#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int cpf;
    char nome[100];
    int fator;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *lst_cria(void)
{
    return NULL;
}
int lst_vazia(Lista *l)
{
    return (l == NULL);
}

Lista *lst_insere_ordenado(Lista *l, int fator, char nome[], int cpf)
{
    Lista *novo;
    Lista *ant = NULL; /* ponteiro para elemento anterior */
    Lista *p = l;      /* ponteiro para percorrer a lista */
    /* procura posição de inserção */
    while (p != NULL && p->fator < fator)
    {
        ant = p;
        p = p->prox;
    }
    /* cria novo elemento */
    novo = (Lista *)malloc(sizeof(Lista));
    novo->fator = fator;
    novo->cpf = cpf;
    strcpy(novo->nome, nome);
    /* encadeia elemento */
    if (ant == NULL)
    { /* insere elemento no início */
        novo->prox = l;
        l = novo;
    }
    else
    { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

void lst_imprime(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d ", p->cpf);
        printf("%s ", p->nome);
        printf("%d ", p->fator);
        printf("\n");
    }
}
// Função para remover todos os elementos de acordo com um fator
Lista* removerPorFator(Lista* l, int fator) {
    Lista* atual = l;
    Lista* anterior = NULL;

    while (atual != NULL) {
        if (atual->fator == fator) {
            // Elemento encontrado, vamos removê-lo
            if (anterior == NULL) {
                // O elemento a ser removido é o primeiro da lista
                l = atual->prox;
                free(atual);
                atual = l; // Atualizamos o ponteiro para o atual
            } else {
                // O elemento a ser removido não é o primeiro da lista
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox; // Atualizamos o ponteiro para o atual
            }
        } else {
            // Elemento não encontrado, continuamos percorrendo a lista
            anterior = atual;
            atual = atual->prox;
        }
    }

    return l;
}
int main()
{
    Lista *l = lst_cria();
    int fator, cpf;
    char nome[100];
    scanf(" %d %d %s", &cpf, &fator, nome);

    l = lst_insere_ordenado(l, fator, nome, cpf);
    scanf(" %d %d %s", &cpf, &fator, nome);
    l = lst_insere_ordenado(l, fator, nome, cpf);
    scanf(" %d %d %s", &cpf, &fator, nome);
    l = lst_insere_ordenado(l, fator, nome, cpf);
    scanf(" %d %d %s", &cpf, &fator, nome);
    l = lst_insere_ordenado(l, fator, nome, cpf);

    printf("\n");
    lst_imprime(l);
    printf("\n");
    l=removerPorFator(l, 2);
    lst_imprime(l);
}