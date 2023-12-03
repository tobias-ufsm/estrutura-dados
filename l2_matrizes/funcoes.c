#include <stdio.h>
#include <stdlib.h>
#define tipoInt 0
#define tipoFloat 1

// Função para alocar uma matriz de elementos do tipo especificado
void** createMatrix(int rows, int cols, size_t elementSize, int tipo) {
    void** matrix = (void**)malloc(rows * sizeof(void*));
    if (matrix == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória para linhas.\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * elementSize);
        if (matrix[i] == NULL) {
            fprintf(stderr, "Erro: Falha na alocação de memória para colunas.\n");
            exit(1);
        }
    }
    return matrix;
}

// Função para preencher a matriz com valores
void fillMatrix(void** matrix, int rows, int cols, size_t elementSize, int tipo) {
	int temp;
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            // Atribuir valores apropriados ao tipo de dados
            if (tipo==0) 
            {
            	printf ("\nDigite um int para [%d][%d]: ", i, j);
				scanf("%d", ((int*)(matrix[i] + j * elementSize)));
			}
             else if (tipo==1) 
             {
             	printf ("\nDigite um float para [%d][%d]: ", i, j);
                scanf("%f", ((float*)(matrix[i] + j * elementSize)));
			 }
/*
explicacao do scanf: 
1) matrix[i] é um ponteiro para a linha i da matriz. Isso nos permite acessar a linha específica na matriz.
2) j * elementSize calcula o deslocamento em bytes para acessar a coluna j dentro da linha i. Isso é necessário porque estamos trabalhando
 com uma matriz de bytes, e elementSize é usado para determinar o tamanho de cada elemento na matriz em bytes.
3) (int*)(matrix[i] + j * elementSize) converte o ponteiro matrix[i] + j * elementSize em um ponteiro para int. Isso é feito para que 
possamos atribuir um valor de tipo int à posição da matriz. A conversão de tipo é feita usando (int*).
*/
}

// Função para imprimir a matriz
void printMatrix(void** matrix, int rows, int cols, size_t elementSize, int tipo) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Imprimir valores apropriados ao tipo de dados
            if (tipo==0) {
                printf("%d\t", *((int*)(matrix[i] + j * elementSize)));
            } else if (tipo==1) {
                printf("%.2f\t", *((float*)(matrix[i] + j * elementSize)));
            }
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada para a matriz
void freeMatrix(void** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows = 2;
    int cols = 2;

    // Exemplo de alocação e uso de uma matriz de inteiros
    void** intMatrix = createMatrix(rows, cols, sizeof(int), tipoInt);
    fillMatrix(intMatrix, rows, cols, sizeof(int), tipoInt);

    printf("Matriz de inteiros:\n", sizeof (int));
    printMatrix(intMatrix, rows, cols, sizeof(int), tipoInt);

    // Liberar a memória alocada para a matriz de inteiros
    freeMatrix(intMatrix, rows);

    // Exemplo de alocação e uso de uma matriz de floats
    void** floatMatrix = createMatrix(rows, cols, sizeof(float), tipoFloat);
    fillMatrix(floatMatrix, rows, cols, sizeof(float), tipoFloat);

    printf("\nMatriz de floats:\n", sizeof (float));
    printMatrix(floatMatrix, rows, cols, sizeof(float), tipoFloat);

    // Liberar a memória alocada para a matriz de floats
    freeMatrix(floatMatrix, rows);

    return 0;
}