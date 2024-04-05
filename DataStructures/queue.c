#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int head, tail, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->head = 0;
    queue->size = 0;
    queue->tail = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    
    return queue;
}

void enqueue(struct Queue* queue, int value) {
    printf("Enqueuing %d value in queue\n", value);
    if (queue->size == queue-> capacity) return;

    queue->tail = (queue -> tail + 1)%queue->capacity;
    queue -> size += 1;
    queue->array[queue->tail] = value;   
}

int dequeue(struct Queue* queue){
    if (queue-> size == 0){
        return -1;
    }
    int value = queue->array[queue -> head];
    queue -> head = (queue -> head + 1) % queue -> capacity;
    queue -> size = queue -> size - 1;
    return value ;
}

void printQueue(struct Queue* queue){
    for(int i = 0; i < queue -> size; i++){
        printf("%d-th queued element is a %d\n", i, queue->array[(queue->head + i)%queue->capacity]);
    }
}

void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    int size = 10;
    int arr[size] = {32, 23, 55, 34, 56, 95, 21, 19, 99, 43}; 

    struct Queue* queue = createQueue(size);
    for (int i = 0; i < size; i++){
        enqueue(queue, arr[i]);
    }


    int lastDequeued = dequeue(queue);
    if (lastDequeued == -1) return - 1;
    printf("first element in queue is  %d\n", lastDequeued);
    printQueue(queue);

    freeQueue(queue);
    
    return 0;
}

// TODO: stack