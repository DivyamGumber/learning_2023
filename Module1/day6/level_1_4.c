#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to compare two students based on marks
int compareStudents(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    // Sort in descending order
    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    }

    return 0;
}

// Function to sort the array of structures in descending order based on marks
void sortStudentArray(struct Student* students, int numStudents) {
    qsort(students, numStudents, sizeof(struct Student), compareStudents);
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Assume the array of structures is initialized before calling sortStudentArray()

    sortStudentArray(students, numStudents);

    printf("\nSorted Student Array:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
