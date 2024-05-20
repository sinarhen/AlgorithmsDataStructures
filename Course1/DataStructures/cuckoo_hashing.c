#include "cuckoo_hashing.h"
#include <stdio.h>

int main() {
    CuckooInterface* cuckoo = createCuckoo(10, hash1, hash2);

    printf("Inserting values...\n");
    for (int i = 0; i < 30; i++) {
        insert(cuckoo, i, 2, 0);
    }

    printf("Printing tables after insertion:\n");
    print(cuckoo);

    printf("Searching for values...\n");
    for (int i = 0; i < 21; i++) {
        int result = search(cuckoo, i);
        if (result != -1) {
            printf("Value %d found in table\n", i);
        } else {
            printf("Value %d not found in table\n", i);
        }
    }

    printf("Deleting values...\n");
    for (int i = 0; i < 20; i++) {
        delete(cuckoo, i);
    }

    printf("Printing tables after deletion:\n");
    print(cuckoo);

    freeCuckoo(cuckoo);

    return 0;
}