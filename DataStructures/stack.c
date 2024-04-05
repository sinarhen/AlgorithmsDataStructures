//
// Created by Bohdan on 05.04.2024.
//


#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top, size;
    unsigned capacity;
    int* array;
};


typedef struct Stack Stack;

Stack* createStack(int size)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = size;
    stack->size = stack->top = 0;
    stack->array = (int*)malloc(sizeof(int) * size);

    return stack;
}

void freeStack(Stack* stack)
{
    free(stack->array);
    free(stack);
}

void stackPush(Stack* stack, int x){
    if (stack->size == stack->capacity) return;
    printf("Pushing into stack on position %d value %d\n", stack->top, x);
    stack->array[stack->top] = x;
    stack->top = (stack->top + 1);
    stack->size = stack->size + 1;
}

int stackPop(Stack* stack){
    if (stack->size == 0) return -1;
    stack->top = stack->top - 1;
    int temp = stack->array[stack->top];
    stack->size = stack->size-1;
    printf("Popped item %d from position %d \n", temp, stack->top + 1);
    return temp;
}

int main(){
    int size = 10;
    int arr[size]; // = {43, 45, 23, 22, 100, 32, 42, 21, 4, 11};

    for (int i = 0; i < size; i++){
        arr[i] = i;
    }
    Stack* stack = createStack(size);
    for (int i = 0; i < size; i++){
        stackPush(stack, arr[i]);
    }

    stackPop(stack);

    freeStack(stack);

    return 0;
}