#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>


struct Queue {
    int head, tail, size;
    unsigned capacity;
    int* array;
};

typedef struct Queue Queue;

Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->head = 0;
    queue->size = 0;
    queue->tail = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    return queue;
}


void enqueue(Queue* queue, int value) {
    printf("Enqueuing %d value in queue\n", value);
    if (queue->size == queue-> capacity) return;

    queue->tail = (queue -> tail + 1)%queue->capacity;
    queue -> size += 1;
    queue->array[queue->tail] = value;
}

int dequeue(Queue* queue){
    if (queue-> size == 0){
        return -1;
    }
    int value = queue->array[queue -> head];
    queue -> head = (queue -> head + 1) % queue -> capacity;
    queue -> size = queue -> size - 1;
    return value ;
}

void printQueue(Queue* queue){
    for(int i = 0; i < queue -> size; i++){
        printf("%d-th queued element is a %d\n", i, queue->array[(queue->head + i)%queue->capacity]);
    }
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}





#endif