#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Livro
{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    int disponivel;
    struct Livro *prox;
}Livro;

Livro* lst_cria(void)
{
    return NULL;
}
Livro* lst_insere(Livro* l)
{
    Livro* novo = (Livro*)malloc(sizeof(Livro));
    printf("Insira o nome do livro: ");
    scanf(" %s", novo->titulo);
    novo->disponivel=1;
    novo->prox = l;
    return novo;
}

void lst_imprime(Livro* l)
{
    Livro* p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%s\n", p->titulo);
    }
}
int lst_vazia(Livro *l)
{
    return (l==NULL);
} 

void emprestaLivro(Livro* lista, char* titulo)
{
    Livro* p = lista;
    if (lista==NULL)
    {
        printf("Lista vazia\n");
        exit(1);
    }
    while (p!=NULL&&strcmp(p->titulo, titulo)!=0)
    {
        p=p->prox;
    }
    if (p==NULL)
    {
        printf("livro nao encontrado\n");
        exit(1);
    }
    else{
        if (p->disponivel==1)
        {
            printf("Livro disponivel\n");
            p->disponivel=0;
        }
        else{
            printf("Livro nao disponivel\n");
        }
        
    }

}

int main()
{
    Livro* l;
    l = lst_cria();
    int livros;
    printf("Quantos livros deseja inserir: ");
    scanf(" %d", &livros);
    for (int i = 0; i < livros; i++)
    {
        l=lst_insere(l);
    }

    char nome[100];
    printf("Digite o nome do livro a ser emprestado: ");
    scanf(" %s", nome);
    emprestaLivro(l, nome);
    
    printf("\n");
    lst_imprime(l);
    return 0;
}