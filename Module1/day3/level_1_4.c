#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    for (int i = 0; i < 4; i++) {
        int temp = num / (int)pow(10, i + 1) * (int)pow(10, i) + num % (int)pow(10, i);
        if (temp > largest) {
            largest = temp;
        }
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNum = findLargestNumber(num);

    printf("Largest number after deleting a digit: %d\n", largestNum);

    return 0;
}
