//
// Created by Bohdan on 10.04.2024.
//

#ifndef DOUBLESTACKQ_H
#define DOUBLESTACKQ_H

#include "stack.h"

struct DoubleStackQ {
    Stack* s1;
    Stack* s2;
};

typedef struct DoubleStackQ DoubleStackQ;

DoubleStackQ* createDoubleStackQ(int capacity){
    DoubleStackQ* q = (DoubleStackQ*)malloc(sizeof(DoubleStackQ));
    q->s1 = createStack(capacity);
    q->s2 = createStack(capacity);
    return q;
}

void doubleStackQEnqueue(DoubleStackQ* q, int el){
    stackPush(q->s1, el);
}

int doubleStackQDequeue(DoubleStackQ* q){

    if (q->s2->top == 0){
        while (q->s1->top > 0){
            int el = stackPop(q->s1);
            stackPush(q->s2, el);
        }
    }
    return stackPop(q->s2);
}


void freeDoubleStackQ(DoubleStackQ* q){
    freeStack(q->s1);
    freeStack(q->s2);
    free(q);
}





#endif DOUBLESTACKQ_H
