#include <stdio.h>

// Structure definition for a box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of a box
double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of a box
double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    // Declare a box structure variable
    struct Box myBox;

    // Assign values to the box dimensions
    myBox.length = 3.0;
    myBox.width = 4.0;
    myBox.height = 5.0;

    // Create a pointer to the box structure
    struct Box *boxPtr = &myBox;

    // Calculate and print the volume using asterisk (*) and dot (.) operators
    double volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    printf("Volume: %.2f\n", volume);

    // Calculate and print the total surface area using arrow (->) operator and dot (.) representation
    double surfaceArea = boxPtr->length * boxPtr->width * boxPtr->height;
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
