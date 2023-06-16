#include <stdio.h>

int getSmallestDigit(int num) {
    int smallest = 9;

    while (num > 0) {
        int digit = num % 10;
        if (digit < smallest) {
            smallest = digit;
        }
        num /= 10;
    }

    return smallest;
}

int getLargestDigit(int num) {
    int largest = 0;

    while (num > 0) {
        int digit = num % 10;
        if (digit > largest) {
            largest = digit;
        }
        num /= 10;
    }

    return largest;
}

void findSmallestLargestDigits(int n, ...) {
    if (n <= 1) {
        printf("Not Valid\n");
        return;
    }

    int smallest = 9;
    int largest = 0;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        int numSmallest = getSmallestDigit(num);
        int numLargest = getLargestDigit(num);

        if (numSmallest < smallest) {
            smallest = numSmallest;
        }

        if (numLargest > largest) {
            largest = numLargest;
        }
    }

    va_end(args);

    printf("Smallest Digit: %d\n", smallest);
    printf("Largest Digit: %d\n", largest);
}

int main() {
    findSmallestLargestDigits(3, 8, 156, 123450);
    return 0;
}
