#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char matricula[10];
    char nome[100];
    int anoIngresso;
};
typedef struct aluno Aluno;

Aluno** aloca_matriz (int m, int n)
{
    Aluno** l = (Aluno **)malloc(m*sizeof(Aluno*));
    for (int i = 0; i < m; i++)
    {
        l[i]=(Aluno *)malloc(n*sizeof(Aluno));
    }
    return l;
}

int main()
{
    int m = 3, n = 3;
    Aluno **turma = aloca_matriz(m , n);
    for (int i = 0; i < m; i++)
    {
        free(turma[i]);
    }
    free(turma);

}