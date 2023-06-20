#include <stdio.h>
#include <stdlib.h>

// Structure definition for a student
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int n;

    // Read the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of students
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }

    // Display data for each student
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
