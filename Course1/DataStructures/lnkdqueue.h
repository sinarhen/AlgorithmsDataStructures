
// Queue with linked list
#ifndef COLORADO_LNKDQUEUE_H
#define COLORADO_LNKDQUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct LnkQueue {
    Node* head;
    Node* tail;
};

typedef struct LnkQueue LnkQueue;

LnkQueue* createLnkQueue() {
    LnkQueue* queue = (LnkQueue*)malloc(sizeof(LnkQueue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(LnkQueue* queue, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

int dequeue(LnkQueue* queue) {
    if (queue->head == NULL) return -1;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    int value = temp->data;
    free(temp);
    return value;
}

void printLnkQueue(LnkQueue* queue) {
    Node* temp = queue->head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeLnkQueue(LnkQueue* queue) {
    Node* temp = queue->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(queue);
}

#endif //COLORADO_LNKDQUEUE_H
// Path: DataStructures/lnkdstack.h