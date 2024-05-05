//
// Created by Bohdan on 05.05.2024.
//

#ifndef COLORADO_CUCKOO_HASHING_H
#define COLORADO_CUCKOO_HASHING_H

#include <stdlib.h>
#include <stdio.h>

typedef struct CuckooInterface{
    int* table1;
    int* table2;
    int size;
} CuckooInterface;

CuckooInterface* createCuckoo(int size, int (*hash1)(int, int), int (*hash2)(int, int)){
    CuckooInterface* cuckoo = malloc(sizeof(CuckooInterface));
    cuckoo->size = size;
    cuckoo->table1 = malloc(size * sizeof(int));
    cuckoo->table2 = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        cuckoo->table1[i] = -1;
        cuckoo->table2[i] = -1;
    }
    return cuckoo;
}

const int MULTIPLICATION_HASHING_CONSTANT = 103;

int hash1(int key, int size){
    return key * MULTIPLICATION_HASHING_CONSTANT % size;
}

int hash2(int key, int size){
    return (key * MULTIPLICATION_HASHING_CONSTANT % size);
}

void insert(CuckooInterface* cuckoo, int key, int table, int iterations){
    if (iterations > cuckoo->size){
        printf("Cuckoo hashing failed\n");
        return;
    }
    int index;
    int temp;
    if (table == 1) {
        index = hash1(key, cuckoo -> size);
        temp = cuckoo->table1[index];
        cuckoo->table1[index] = key;
        if (temp != -1 && temp != key){
            insert(cuckoo, temp, 2, iterations + 1);
        }
    } else if (table == 2) {
        index = hash2(key, cuckoo -> size);
        temp = cuckoo->table2[index];
        cuckoo->table2[index] = key;
        if (temp != -1 && temp != key){
            insert(cuckoo, temp, 1, iterations + 1);
        }
    }
}

int search(CuckooInterface* cuckoo, int key){
    int index1 = hash1(key, cuckoo -> size);
    if (cuckoo -> table1[index1] == key)
        return index1;

    int index2 = hash2(key, cuckoo -> size);
    if (cuckoo -> table2[index2] == key)
        return index2;
    return -1;
}

void delete(CuckooInterface* cuckoo, int key){
    int index1 = hash1(key, cuckoo -> size);
    if (cuckoo -> table1[index1] == key){
        cuckoo -> table1[index1] = -1;
        return;
    }

    int index2 = hash2(key, cuckoo -> size);
    if (cuckoo -> table2[index2] == key)
        cuckoo -> table2[index2] = -1;
}

void print(CuckooInterface* cuckoo){
    printf("Table 1: ");
    for (int i = 0; i < cuckoo->size; i++) {
        printf("%d ", cuckoo->table1[i]);
    }
    printf("\nTable 2: ");
    for (int i = 0; i < cuckoo->size; i++) {
        printf("%d ", cuckoo->table2[i]);
    }
    printf("\n");
}

void freeCuckoo(CuckooInterface* cuckoo){
    free(cuckoo->table1);
    free(cuckoo->table2);
    free(cuckoo);
}

#endif //COLORADO_CUCKOO_HASHING_H
