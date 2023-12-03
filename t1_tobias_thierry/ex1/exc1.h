#ifndef EXC1_H
#define EXC1_H

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct esparsa
{
    int linhas;
    int colunas;
    struct lista *prim;
};
typedef struct esparsa Esparsa;

struct diagonal
{
    int ordem;
    int *v;
};
typedef struct diagonal Diagonal;



Lista *criarElemento(int linha, int coluna, int valor); 
void adicionarElemento(Esparsa *matrizEsparsa, int linha, int coluna, int valor);
Diagonal extrairDiagonalPrincipal(Esparsa *matrizEsparsa);
void imprimirDiagonal(Diagonal diagonal);

#endif

