//
// Created by Bohdan on 06.04.2024.
//

#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int* array;
    int capacity;
    int size;
};

typedef struct Heap Heap;

Heap* createHeap(int capacity, const int* arr) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int *) malloc(sizeof(int) * capacity);

    for (int i = 0; i < capacity; i++){
        heap->array[i] = arr[i];
        heap->size += 1;
    }
    return heap;
}


void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
void bubbleUpMaxHeap(Heap* heap, int i){
    if (i <= 0){
        return;
    }
    if (heap->array[i] > heap->array[(i - 1) / 2]){
        swap(heap->array, i, (i - 1) / 2);
        bubbleUpMaxHeap(heap, (i - 1) / 2);
    }
}

void bubbleDownMaxHeap(Heap* heap, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < heap->size && heap->array[left] > heap->array[largest]){
        largest = left;
    }
    if (right < heap->size && heap->array[right] > heap->array[largest]){
        largest = right;
    }
    if (largest != i){
        swap(heap->array, i, largest);
        bubbleDownMaxHeap(heap, largest);
    }
}

void bubbleDownMinHeap(Heap* heap, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap->size && heap->array[left] < heap->array[smallest]){
        smallest = left;
    }
    if (right < heap->size && heap->array[right] < heap->array[smallest]){
        smallest = right;
    }
    if (smallest != i){
        swap(heap->array, i, smallest);
        bubbleDownMinHeap(heap, smallest);
    }

}

void bubbleUpMinHeap(Heap* heap, int i){
    if (i<=0){
        return;
    }
    if (heap->array[i] < heap->array[i / 2]){
        swap(heap->array, i, i / 2);
        bubbleUpMinHeap(heap, i / 2);
    }
}


void buildMinHeap(Heap* heap){
    for (int i = heap->size / 2 - 1; i >= 0 ; i--){
        bubbleDownMinHeap(heap, i);
    }
}

void freeHeap(Heap* heap){
    free(heap->array);
    free(heap);
}


void buildMaxHeap(Heap* heap){
    for (int i = heap->size / 2 - 1; i >= 0 ; i--){
        bubbleDownMaxHeap(heap, i);
    }
}

void printHeapArray(Heap* heap){
    printf("{ ");

    for (int i = 0; i < heap->size; i++){
        printf("%d", heap->array[i]);
        if (i != heap->size - 1){
            printf(",");
        }
    }

    printf(" }\n");
}

void heapSort(Heap* heap){ // If min heap then ascending
    for (int i = heap->size - 1; i > 1; i--){
        swap(heap->array, 0, i);
        // heap->size = heap->size - 1;
        buildMaxHeap(heap);
    }

}


void printHeap(Heap* heap){

    for (int i = 0; i < heap->size; i++){
        printf("Heap key %d\n", heap->array[i]);
        if (i < heap->size / 2){
            printf("\tHeap left %d\n", heap->array[i*2]);
        }
        if (i < heap->size / 2 - 1){
            printf("\tHeap right %d\n", heap->array[i * 2 + 1]);
        }

    }
}



int main (){
    const int size = 10;
    int arr[10] = {10, 23, 43, 22, 11, 100, 55, 62, 1, 3};

    Heap* heap = createHeap(size, arr);
    printf("Initial heap:\n");
    printHeapArray(heap);

    buildMaxHeap(heap);
    printf("Heap after maxHeapify:\n");
    printHeapArray(heap);

    bubbleUpMaxHeap(heap, 9);
    printf("Heap after bubbleUp [9]:\n");
    printHeapArray(heap);

    printf("Sorted array from heap");
    heapSort(heap);
    printHeapArray(heap);

    freeHeap(heap);
    return 0;
}