#include <stdio.h>

int bit_operations(int num, int oper_type) {
    if (oper_type == 1) {
        // Set 1st bit
        num |= 1;
    } else if (oper_type == 2) {
        // Clear 31st bit
        num &= ~(1 << 31);
    } else if (oper_type == 3) {
        // Toggle 16th bit
        num ^= 1 << 16;
    }

    return num;
}

int main() {
    int num1 = 42;
    int oper_type1 = 1;
    int result1 = bit_operations(num1, oper_type1);
    printf("Result 1: %d\n", result1);

    int num2 = 12345;
    int oper_type2 = 3;
    int result2 = bit_operations(num2, oper_type2);
    printf("Result 2: %d\n", result2);

    return 0;
}
