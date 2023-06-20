#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the input string and initialize the array of structures
void initializeStudentArray(struct Student* students, int numStudents, char* inputString) {
    char* token;
    char delimiters[] = " ";
    int count = 0;

    token = strtok(inputString, delimiters);
    while (token != NULL && count < numStudents) {
        students[count].rollno = atoi(token);

        token = strtok(NULL, delimiters);
        strcpy(students[count].name, token);

        token = strtok(NULL, delimiters);
        students[count].marks = atof(token);

        count++;

        token = strtok(NULL, delimiters);
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Consume the newline character after reading numStudents
    getchar();

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    char inputString[MAX_STRING_LENGTH];
    printf("Enter the student details: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    // Remove the newline character at the end of inputString
    inputString[strcspn(inputString, "\n")] = '\0';

    initializeStudentArray(students, numStudents, inputString);

    // Print the initialized array of structures
    printf("\nInitialized Student Array:\n");
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
