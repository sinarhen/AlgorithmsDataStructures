#include <stdio.h>
#include "queue.h"


int main() {
    int size = 10;
    int arr[size];


    Queue* queue = createQueue(size);
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