#include <stdio.h>

int linearSearch(int array[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int array[] = {30, 40, 10, 60, 50, 20, 70, 90, 80, 25};
    int length = sizeof(array) / sizeof(array[0]);

    int target = 80;

    int index = linearSearch(array, length, target);

    if (index != -1) {
        printf("Target %d found at index %d\n", target, index);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
