#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct LnkStack  {
    Node* top;
};

typedef struct LnkStack LnkStack;

LnkStack* createLnkStack() {
    LnkStack* stack = (LnkStack*)malloc(sizeof(LnkStack));
    stack->top = NULL;
    return stack;
}

void push(LnkStack* stack, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = stack->top;
    stack->top = node;
}

int pop(LnkStack* stack) {
    if (stack->top == NULL) return -1;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int value = temp->data;
    free(temp);
    return value;
}

void printLnkStack(LnkStack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeLnkStack(LnkStack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(stack);
}





