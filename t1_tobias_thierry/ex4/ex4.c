#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex4.h"

void **allocate_matrix(int rows, int columns, size_t size_type)
{
    void **matrix = (void **)malloc(rows * sizeof(void *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(columns * size_type);
    }
    return matrix;
}
void fill_matrix(void **matrix, int rows, int columns, size_t size_type)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (size_type == sizeof(int))
            {
                scanf(" %d", (int *)(matrix[i] + j * size_type));
            }
            else if (size_type == sizeof(float))
            {
                scanf(" %f", (float *)(matrix[i] + j * size_type));
            }
            else if (size_type == sizeof(double))
            {

                scanf(" %lf", (double *)(matrix[i] + j * size_type));
            }
            else if (size_type == sizeof(char))
            {

                scanf(" %c", (char *)(matrix[i] + j * size_type));
            }
        }
    }
}
void print_matrix(void **matrix, int rows, int columns, size_t size_type)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (size_type == sizeof(int))
            {
                printf("%d ", *((int *)(matrix[i] + j * size_type)));
            }
            else if (size_type == sizeof(float))
            {
                printf("%.2f ", *((float *)(matrix[i] + j * size_type)));
            }
            else if (size_type == sizeof(double))
            {
                printf("%.2lf ", *((double *)(matrix[i] + j * size_type)));
            }
            else if (size_type == sizeof(char))
            {
                printf("%c ", *((char *)(matrix[i] + j * size_type)));
            }
        }
        printf("\n");
    }
}

int ***allocate_matrix_3d(int rows, int columns, int depth)
{
    int ***matrix = (int ***)malloc(rows * sizeof(int **));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int **)malloc(columns * sizeof(int *));
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = (int *)malloc(depth * sizeof(int));
        }
    }
    return matrix;
}
void fill_matrix_3d(int ***matrix, int rows, int columns, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < columns; k++)
            {
                scanf("%d", &matrix[j][k][i]);
            }
        }
    }
}
void print_matrix_3d(int ***matrix, int rows, int columns, int depth)
{
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < columns; k++)
            {
                printf("%d ", matrix[j][k][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
void desallocate_matrix_3d(int ***matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}