#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure for student
typedef struct {
    int roll;
    char name[50];
    char class[50];
} Student;

// Function declarations
void addStudent(Student students[], int *count);
void searchStudent(Student students[], int count);
void deleteStudent(Student students[], int *count);
void printStudentList(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 10; // Preload with 10 students
    int choice;

    // Preload with 10 students
    for (int i = 0; i < 10; i++) {
        students[i].roll = i + 1;
        sprintf(students[i].name, "Student%d", i + 1);
        sprintf(students[i].class, "Class%d", (i % 5) + 1);
    }

    while (1) {
        printf("\n--- Student List Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Print Student List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                printStudentList(students, count);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll);
    printf("Enter name: ");
    scanf(" %[^\n]", students[*count].name);
    printf("Enter class: ");
    scanf(" %[^\n]", students[*count].class);
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to search a student
void searchStudent(Student students[], int count) {
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Student found: Roll=%d, Name=%s, Class=%s\n",
                   students[i].roll, students[i].name, students[i].class);
            return;
        }
    }
    printf("Student with roll number %d not found!\n", roll);
}

// Function to delete a student
void deleteStudent(Student students[], int *count) {
    int roll, index = -1;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < *count; i++) {
        if (students[i].roll == roll) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll number %d not found!\n", roll);
        return;
    }
    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    printf("Student deleted successfully!\n");
}

// Function to print all students
void printStudentList(Student students[], int count) {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll=%d, Name=%s, Class=%s\n", students[i].roll, students[i].name, students[i].class);
    }
}
