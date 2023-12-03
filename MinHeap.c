#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct 
{
    int *array;
    int size;
    int capacity;
} Heap;


Heap* initializeHeap(int capacity) 
{
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->array = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Heap *heap, int value) 
{
    if (heap->size == heap->capacity) 
    {
        printf("Heap cheio. Impossível inserir.\n");
        return;
    }

    heap->array[heap->size] = value;
    int current = heap->size;

    while (current > 0 && heap->array[current] < heap->array[(current - 1) / 2])
    {
        swap(&heap->array[current], &heap->array[(current - 1) / 2]);
        current = (current - 1) / 2;
    }

    heap->size++;
}

void removeRoot(Heap *heap) 
{
    if (heap->size == 0) {
        printf("Heap vazio. Impossível remover.\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    int current = 0;
    while (1) {
        int leftChild = 2 * current + 1;
        int rightChild = 2 * current + 2;
        int smallest = current;

        if (leftChild < heap->size && heap->array[leftChild] < heap->array[smallest]) 
        {
            smallest = leftChild;
        }

        if (rightChild < heap->size && heap->array[rightChild] < heap->array[smallest]) 
        {
            smallest = rightChild;
        }

        if (smallest != current) 
        {
            swap(&heap->array[current], &heap->array[smallest]);
            current = smallest;
        }
        else 
        {
            break;
        }
    }
}

void printHeap(Heap *heap, int index, int depth) 
{
    if (index < heap->size) 
    {
        printf("Valor: %d, Filho Esquerdo: ", heap->array[index]);
        if (2 * index + 1 < heap->size) 
        {
            printf("%d, ", heap->array[2 * index + 1]);
        }
        else 
        {
            printf("N/A, ");
        }

        printf("Filho Direito: ");
        if (2 * index + 2 < heap->size) 
        {
            printf("%d", heap->array[2 * index + 2]);
        }
        else 
        {
            printf("N/A");
        }
        printf("\n");
        
        printHeap(heap, 2 * index + 1, depth + 1);
        printHeap(heap, 2 * index + 2, depth + 1);
    }
}


void menu(Heap *heap)
{
    while (1)
    {
        int num, valor;
        printf("Escolha a sua opcao:\n 1 - Inserir\n 2 - Remover\n 3 - Imprimir heap\n 4 - Sair\n");
        scanf("%d", &num);
        if (num != 1 && num != 2 && num != 3) 
        {
            break;
        }
        else if (num == 1)
        {
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            insert(heap, valor);
            printf("O valor %d foi adicionado ao heap\n", valor);
        }
        else if (num == 2)
        {
            removeRoot(heap);
        }
        else if (num == 3)
        {
            printHeap(heap, 0, 0);
        }   
        else if (num == 4)
        {
            return;
        }
        
    }
}


int main() 
{
    Heap *heap = initializeHeap(MAX_HEAP_SIZE);
    printf("Heap com implementacao de tipo min-heap\n");
    menu(heap);
    free(heap->array);
    free(heap);
    return 0;
}
