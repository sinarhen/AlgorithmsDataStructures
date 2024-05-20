#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};


typedef struct Stack Stack;

Stack* createStack(int size)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = size;
    stack->top = 0;
    stack->array = (int*)malloc(sizeof(int) * size);

    return stack;
}

void freeStack(Stack* stack)
{
    free(stack->array);
    free(stack);
}

void stackPush(Stack* stack, int x){
    if (stack->top == stack->capacity) return;
    stack->array[stack->top] = x;
    stack->top = (stack->top + 1);
}

int stackPop(Stack* stack){
    if (stack->top == 0) return -1;
    stack->top = stack->top - 1;
    int temp = stack->array[stack->top];
    return temp;
}



#endif