#include <stdio.h>

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    printArray(array, length);

    // Perform the reversals
    for (int i = 0; i < length / 2; i++) {
        int temp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temp;

        printf("Case %d: ", i + 1);
        printArray(array, length);
    }

    return 0;
}
