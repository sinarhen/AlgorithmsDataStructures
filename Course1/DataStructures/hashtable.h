//
// Created by Bohdan on 28.04.2024.
//

#ifndef COLORADO_HASHTABLE_H
#define COLORADO_HASHTABLE_H

#include <stdlib.h>
#include <string.h>

typedef struct Hashtable {
    int size;
    char** table;
} Hashtable;

Hashtable* createHashtable(int capacity){
    Hashtable* hashtable = (Hashtable*)malloc(sizeof(Hashtable));
    hashtable->size = capacity;
    hashtable->table = (char**)malloc(capacity * sizeof(char*));
    for (int i = 0; i < capacity; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

unsigned int hash(Hashtable* hashtable, char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = 31 * hash + key[i];
    }
    return hash % hashtable->size;
}

void insert(Hashtable* hashtable, char* key) {
    int index = hash(hashtable, key);
    while (hashtable->table[index] != NULL) {
        index++;
        index %= hashtable->size;
    }
    hashtable->table[index] = strdup(key);
}

int search(Hashtable* hashtable, char* key) {
    int index = hash(hashtable, key);
    while (hashtable->table[index] != NULL) {
        if (strcmp(hashtable->table[index], key) == 0) {
            return index;
        }
        index++;
        index %= hashtable->size;
    }
    return -1;
}

#endif //COLORADO_HASHTABLE_H
