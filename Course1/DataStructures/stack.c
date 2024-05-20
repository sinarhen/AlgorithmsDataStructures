//
// Created by Bohdan on 05.04.2024.
//



#include "stack.h"

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