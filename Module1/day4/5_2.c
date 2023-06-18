#include <stdio.h>

int main() {
    int array[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int length = sizeof(array) / sizeof(array[0]);
    int min = array[0];
    int max = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
