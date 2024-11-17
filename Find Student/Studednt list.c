#include <stdio.h>       // print korar jonno use kora hoiseee
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100 // eita diye amra max student er list banannor jonno niyeci
#define NAME_LEN 50      // 50 joner name amra edit korte parbo


typedef struct {                //student er list ta kemon hobe seta
    char name[NAME_LEN];
    int roll;
    int class;
} Student;

Student students[MAX_STUDENTS];
int total_students = 50;


void initialize_students();            // amader ki ki udeshho (prototyes)
void add_student();
void find_student();
void delete_student();
void display_students();
int find_student_index(const char* name);

int main() {                           // amder main function (mul udeshho)
    int choice;
    initialize_students();

    while (1) {                                      //loop use korci jate onek gula kaj aksate kaj korte pari ar somoy kom lage
        printf("\nStudent Management System:\n");    //display for user's
        printf("1. Add a student\n");
        printf("2. Find a student by name\n");
        printf("3. Delete a student\n");
        printf("4. Display all students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);                       // user input kon ta choice korbe bah kon tar jonno kaj korbe

        switch (choice) {                           //switch case calaici ar break use korci jate kore amra akta niye kaj korle aktatei code rune  kore ar onno kisu kaj na kore
            case 1:
                add_student();
                break;
            case 2:
                find_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                display_students();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");  // default  er jonno niyeci

        }
    }
    return 0;
}

void initialize_students() {                    // age theke list er modhe 50 jon student niyecilam
    for (int i = 0; i < total_students; i++) {
        sprintf(students[i].name, "Student_%d", i + 1);
        students[i].roll = i + 1;
        students[i].class = (i % 10) + 1;            // Classes er je  range hobe  seta  from 1 to 10 porjonto bindoman thakbe
    }
}

void add_student() {                                                  // amra jokhn anta new student niyeci setar jonno function
    if (total_students >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    Student new_student;
    printf("Enter student's name: ");
    scanf(" %[^\n]", new_student.name);
    printf("Enter student's roll number: ");
    scanf("%d", &new_student.roll);
    printf("Enter student's class: ");
    scanf("%d", &new_student.class);

    students[total_students] = new_student;
    total_students++;
    printf("Student added successfully!\n");
}


void find_student() {                        // student khujar jonno amra ei function use koreci
    char name[NAME_LEN];
    printf("Enter student's name to find: ");
    scanf(" %[^\n]", name);

    int index = find_student_index(name);
    if (index == -1) {
        printf("Student not found.\n");
    } else {
        printf("Student found:\n");
        printf("Name: %s, Roll: %d, Class: %d\n", students[index].name, students[index].roll, students[index].class);
    }
}


void delete_student() {                        +89          // amra je student delete korbo tar jonno ei function create koreci
    char name[NAME_LEN];
    printf("Enter student's name to delete: ");
    scanf(" %[^\n]", name);
     return 1;
    int index = find_student_index(name);
    if (index == -1) {
        printf("Student not found.\n");
    } else {
        for (int i = index; i < total_students - 1; i++) {
            students[i] = students[i + 1];
        }
        total_students--;
        printf("Student deleted successfully!\n");
    }
}


void display_students() {                             // amra je update student list ta dekhte parbo tar jonno fumction
    printf("Current list of students:\n");
    for (int i = 0; i < total_students; i++) {
        printf("Name: %s, Roll: %d, Class: %d\n", students[i].name, students[i].roll, students[i].class);
    }
}


int find_student_index(const char* name) {              // index er modhe name diye kono student khojar khetre amra ei function use koreci

    for (int i = 0; i < total_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
