#include <stdio.h>

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {30, 40, 10, 60, 50, 20};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    printArray(array, length);

    // Perform the exchanges
    printf("Case 1: ");
    printArray(array, length);

    // Second case: 30 10 40 60 50 20
    printf("Case 2: ");
    int temp = array[1];
    array[1] = array[2];
    array[2] = temp;
    printArray(array, length);

    // Third case: 30 10 40 60 50 20
    printf("Case 3: ");
    printArray(array, length);

    // Fourth case: 30 10 40 50 60 20
    printf("Case 4: ");
    temp = array[4];
    array[4] = array[5];
    array[5] = temp;
    printArray(array, length);

    // Fifth case: 30 10 40 50 20 60
    printf("Case 5: ");
    temp = array[4];
    array[4] = array[5];
    array[5] = temp;
    printArray(array, length);

    return 0;
}
