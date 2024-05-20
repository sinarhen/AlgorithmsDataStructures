#include "doubleqstack.h"
#include <stdio.h>


// 1. Create a DoubleQStack
// 2. Створений DoubleQStack має дві черги з однаковими розмірами
// 3. Щоб додати елементи до стеку нам необхідно вибрати одну з черг і додати елемент в кінець черги
// 4. Після того як ми додали елемент до черги, ми повинні видалити всі елементи з іншої черги і додати їх до першої черги. Це робиться для того аби черга повертала
// 5. Якщо ми хочемо видалити елемент зі стеку, ми повинні видалити елемент з черги, яка містить елементи стеку
// 6. Якщо ми хочемо додати елемент до стеку, ми повинні додати елемент до черги, яка містить елементи стеку

int main(){
    int size = 10;
    int arr[size];

    printf("Initializing array...\n");
    for (int i = 0; i < size; i++){
        arr[i] = i;
        printf("Added %d to array\n", i);
    }

    printf("Creating DoubleQStack...\n");
    DoubleQStack* stack = createDoubleQStack(size);

    printf("Pushing elements to stack...\n");
    for (int i = 0; i < size; i++){
        pushDoubleQStack(stack, arr[i]);
        printf("Pushed %d to stack\n", arr[i]);
    }

    printf("Popping element from stack...\n");
    int popped = popDoubleQStack(stack);
    printf("Popped %d from stack\n", popped);

    printf("Freeing DoubleQStack...\n");
    freeDoubleQStack(stack);

    printf("Process finished successfully.\n");
    return 0;
}