#include <stdio.h>
#include <stdint.h>

void print_exponent_part(double x) {
    uint64_t bits;
    uint64_t *ptr = (uint64_t *)&x;
    bits = *ptr;

    uint64_t exponent_bits = (bits >> 52) & 0x7FF;

    printf("Exponent in hexadecimal: 0x%llX\n", exponent_bits);
    printf("Exponent in binary: 0b");

    for (int i = 10; i >= 0; i--) {
        int bit = (exponent_bits >> i) & 1;
        printf("%d", bit);
    }

    printf("\n");
}

int main() {
    double x = 0.7;
    print_exponent_part(x);

    return 0;
}