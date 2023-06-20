#include <stdio.h>
#include <stdlib.h>

// Structure definition for a student
struct Student {
    char name[50];
    int age;
};

// Function to modify the members of the structure using a pointer
struct Student* modifyStudent(struct Student* student) {
    printf("Enter the student's name: ");
    scanf("%s", student->name);

    printf("Enter the student's age: ");
    scanf("%d", &(student->age));

    return student;
}

int main() {
    struct Student* studentPtr;
    struct Student student;

    studentPtr = modifyStudent(&student);

    printf("\nModified Student Details:\n");
    printf("Name: %s\n", studentPtr->name);
    printf("Age: %d\n", studentPtr->age);

    return 0;
}
