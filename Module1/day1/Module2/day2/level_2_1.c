#include <stdio.h>

int findGreatest(int num1, int num2, int num3) {
    int greatest = num1;

    if (num2 > greatest) {
        greatest = num2;
    }

    if (num3 > greatest) {
        greatest = num3;
    }

    return greatest;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    int num3 = 15;

    int result = findGreatest(num1, num2, num3);
    printf("The greatest number is: %d\n", result);

    return 0;
}
