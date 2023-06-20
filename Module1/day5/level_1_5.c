#include <stdio.h>

// Structure definition for a point
struct Point {
    int x;
    int y;
};

// Function to swap the fields of two points using pointers
void swapPoints(struct Point* p1, struct Point* p2) {
    int tempX = p1->x;
    int tempY = p1->y;

    p1->x = p2->x;
    p1->y = p2->y;

    p2->x = tempX;
    p2->y = tempY;
}

int main() {
    struct Point point1, point2;

    // Read the coordinates of point1
    printf("Enter the coordinates of point1 (x y): ");
    scanf("%d %d", &point1.x, &point1.y);

    // Read the coordinates of point2
    printf("Enter the coordinates of point2 (x y): ");
    scanf("%d %d", &point2.x, &point2.y);

    printf("\nBefore Swapping:\n");
    printf("Point1: (%d, %d)\n", point1.x, point1.y);
    printf("Point2: (%d, %d)\n", point2.x, point2.y);

    // Swap the fields of point1 and point2
    swapPoints(&point1, &point2);

    printf("\nAfter Swapping:\n");
    printf("Point1: (%d, %d)\n", point1.x, point1.y);
    printf("Point2: (%d, %d)\n", point2.x, point2.y);

    return 0;
}
