#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// Structure definition for a student
struct Student {
    char name[MAX_NAME_LENGTH];
    int marks;
};

// Function to read data for each student
void readStudentData(struct Student* student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter student marks: ");
    scanf("%d", &student->marks);
}

// Function to write data for each student
void writeStudentData(struct Student student) {
    printf("Name: %s, Marks: %d\n", student.name, student.marks);
}

// Function to compute the average marks for a class
float computeAverage(struct Student* students, int numStudents) {
    int totalMarks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i].marks;
    }
    return (float)totalMarks / numStudents;
}

// Function to display students above and below average marks
void displayAboveBelowAverage(struct Student* students, int numStudents, float average) {
    printf("Students scoring above average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > average) {
            writeStudentData(students[i]);
        }
    }

    printf("Students scoring below average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < average) {
            writeStudentData(students[i]);
        }
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for an array of students
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Read data for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        readStudentData(&students[i]);
    }

    // Compute average marks for the class
    float averageMarks = computeAverage(students, numStudents);

    printf("\nClass Average Marks: %.2f\n", averageMarks);

    // Display students above and below average marks
    displayAboveBelowAverage(students, numStudents, averageMarks);

    // Free dynamically allocated memory
    free(students);

    return 0;
}
