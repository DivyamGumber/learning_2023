#include <stdio.h>

int main() {
    int array[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int length = sizeof(array) / sizeof(array[0]);

    int sumEvenIndex = 0;
    int sumOddIndex = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            sumEvenIndex += array[i];
        } else {
            sumOddIndex += array[i];
        }
    }

    int difference = sumEvenIndex - sumOddIndex;

    printf("Sum of elements at even indexes: %d\n", sumEvenIndex);
    printf("Sum of elements at odd indexes: %d\n", sumOddIndex);
    printf("Difference: %d\n", difference);

    return 0;
}
