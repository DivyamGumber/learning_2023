#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calculateDistance(struct Point p1, struct Point p2) {
    double distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main() {
    struct Point point1, point2;
    double distance;

    printf("Enter the coordinates of point1 (x y): ");
    scanf("%lf %lf", &point1.x, &point1.y);

    printf("Enter the coordinates of point2 (x y): ");
    scanf("%lf %lf", &point2.x, &point2.y);

    distance = calculateDistance(point1, point2);

    printf("The distance between the two points is: %.2lf\n", distance);

    return 0;
}
