//
// Created by Bohdan on 06.04.2024.
//

#include <stdio.h>
#include <stdlib.h>


struct HeapKey{
    int key;
    int right;
    int left;
};
typedef struct HeapKey HeapKey;

struct Heap {
    HeapKey* array;
    int capacity;
    int size;
};

typedef struct Heap Heap;

Heap* createHeap(int capacity, int* arr){
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (HeapKey*)malloc(sizeof(HeapKey) * capacity);

    for (int i = 0; i < capacity; i++){
        heap->array[i].key = arr[i];
        heap->array[i].left = 2*i + 1;
        heap->array[i].right = 2*i + 2;
    }
    heap->size = capacity;

    return heap;
}
void minHeapify(Heap* heap){
    int i = 0;
    while (i < heap->size/2){
        int left = 2*i;
        int right = 2*i + 1;
        int smallest = i;
        if (heap->array[left].key < heap->array[i].key){
            smallest = left;
        }
        if (heap->array[right].key < heap->array[smallest].key){
            smallest = right;
        }
        if (smallest != i){
            HeapKey temp = heap->array[i];
            heap->array[i] = heap->array[smallest];
            heap->array[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
        i++;
    }
}

void freeHeap(Heap* heap){
    free(heap->array);
    free(heap);
}

int main (){
    int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++){
        arr[i] = i;
    }
    Heap* heap = createHeap(size, arr);
//    minHeapify(heap);

    for (int i = 0; i < size; i++){
        printf("Heap key %d\n", heap->array[i].key);
        printf("Heap left %d\n", heap->array[i].left);
        printf("Heap right %d\n", heap->array[i].right);
    }


    freeHeap(heap);
    return 0;
}