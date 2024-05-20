//
// Created by Bohdan on 28.04.2024.
//

#include "hashtable.h"

#include <stdio.h>

int main() {
    Hashtable* hashtable = createHashtable(10);

    insert(hashtable, "test1");
    insert(hashtable, "test2");
    insert(hashtable, "test3");

    printf("Searching for 'test1': %d\n", search(hashtable, "test1"));
    printf("Searching for 'test2': %d\n", search(hashtable, "test2"));
    printf("Searching for 'test4': %d\n", search(hashtable, "test4"));

    return 0;
}