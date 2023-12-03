#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void allocate_matrix(int ***matrix, int rows, int columns)
{
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        (*matrix)[i] = (int *)malloc(columns * sizeof(int));
    }
    int cont=1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            (*matrix)[i][j]=cont;
            cont++;
        }
        
    }
    
}
int main()
{
    int l=3, c=3;
    int **matriz;
    allocate_matrix(&matriz, l, c);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
        
    }
    

}