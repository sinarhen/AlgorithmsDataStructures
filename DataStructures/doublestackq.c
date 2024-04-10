#include "doublestackq.h"
#include <stdio.h>

int main(){
    int size = 10;
    int arr[size];

    printf("Initializing array...\n");
    for (int i = 0; i < size; i++){
        arr[i] = i;
        printf("Added %d to array\n", i);
    }

    printf("Creating DoubleStackQ...\n");
    DoubleStackQ* q = createDoubleStackQ(size);

    printf("Enqueueing elements to DoubleStackQ...\n");
    for (int i = 0; i < size; i++){
        doubleStackQEnqueue(q, arr[i]);
        printf("Enqueued %d to DoubleStackQ\n", arr[i]);
    }

    int dequeued;
    for (int i = 0; i < 2; i++){
        printf("Dequeuing element from DoubleStackQ...\n");
        dequeued = doubleStackQDequeue(q);
        printf("Dequeued %d from DoubleStackQ\n", dequeued);
    }



    for (int i = 0; i < 2; i++){
        doubleStackQEnqueue(q, arr[i]);
        printf("Enqueued %d to DoubleStackQ\n", arr[i]);
    }
    for (int i = 0; i < 2; i++){
        printf("Dequeuing element from DoubleStackQ...\n");
        dequeued = doubleStackQDequeue(q);
        printf("Dequeued %d from DoubleStackQ\n", dequeued);
    }


    printf("Freeing DoubleStackQ...\n");
    freeDoubleStackQ(q);

    printf("Process finished successfully.\n");
    return 0;
}