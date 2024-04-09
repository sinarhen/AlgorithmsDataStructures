//
// Created by Bohdan on 09.04.2024.
//

#ifndef COLORADO_DOUBLEQSTACK_H
#define COLORADO_DOUBLEQSTACK_H

#include "queue.h"

struct DoubleQStack {
    Queue* q1;
    Queue* q2;
};

typedef struct DoubleQStack DoubleQStack;

DoubleQStack* createDoubleQStack(unsigned capacity) {
    DoubleQStack* stack = (DoubleQStack*)malloc(sizeof(DoubleQStack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

void pushDoubleQStack(DoubleQStack* stack, int value) {
    if (stack->q1->size == stack->q1->capacity) return;
    enqueue(stack->q1, value);
}

int popDoubleQStack(DoubleQStack* stack) {
    if (stack->q1->size == 0) return -1;
    while (stack->q1->size != 1) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int value = dequeue(stack->q1);
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return value;
}

void freeDoubleQStack(DoubleQStack* stack) {
    freeQueue(stack->q1);
    freeQueue(stack->q2);
    free(stack);
}


#endif //COLORADO_DOUBLEQSTACK_H
