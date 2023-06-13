#include <stdio.h>

int find_biggest_number(int a, int b) {
    int biggest_number;
    
    // Using if-else statements
    if (a > b) {
        biggest_number = a;
    } else {
        biggest_number = b;
    }
    
    // Using the ternary operator
    biggest_number = (a > b) ? a : b;
    
    return biggest_number;
}

int main() {
    int num1, num2, biggest;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    biggest = find_biggest_number(num1, num2);
    
    printf("The biggest number is: %d\n", biggest);
    
    return 0;
}