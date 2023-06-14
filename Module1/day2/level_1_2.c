#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *ptr1 = (unsigned char *)a;
    unsigned char *ptr2 = (unsigned char *)b;
    unsigned char temp;
    
    for (size_t i = 0; i < size; i++) {
        temp = *(ptr1 + i);
        *(ptr1 + i) = *(ptr2 + i);
        *(ptr2 + i) = temp;
    }
}

int main() {
    int num1 = 10;
    int num2 = 20;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    double value1 = 3.14;
    double value2 = 2.71;

    printf("Before swapping: value1 = %lf, value2 = %lf\n", value1, value2);
    swap(&value1, &value2, sizeof(double));
    printf("After swapping: value1 = %lf, value2 = %lf\n", value1, value2);

    char char1 = 'A';
    char char2 = 'B';

    printf("Before swapping: char1 = %c, char2 = %c\n", char1, char2);
    swap(&char1, &char2, sizeof(char));
    printf("After swapping: char1 = %c, char2 = %c\n", char1, char2);

    return 0;
}