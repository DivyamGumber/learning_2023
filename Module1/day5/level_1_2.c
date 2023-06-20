#include <stdio.h>

// Structure definition for a complex number
struct Complex {
    double real;
    double imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex *c) {
    printf("Enter the real part: ");
    scanf("%lf", &c->real);
    printf("Enter the imaginary part: ");
    scanf("%lf", &c->imaginary);
}

// Function to write a complex number
void writeComplex(struct Complex c) {
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    // Read the first complex number
    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    // Read the second complex number
    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    // Write the complex numbers
    printf("First complex number:\n");
    writeComplex(complex1);
    printf("Second complex number:\n");
    writeComplex(complex2);

    // Add the complex numbers
    sum = addComplex(complex1, complex2);
    printf("Sum of the complex numbers:\n");
    writeComplex(sum);

    // Multiply the complex numbers
    product = multiplyComplex(complex1, complex2);
    printf("Product of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
