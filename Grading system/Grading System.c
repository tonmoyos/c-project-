#include <stdio.h>

int calculateGrade(int marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
     return 'C';
    else if (marks >= 60)
     return 'D';
    else if (marks >= 33)
     return 'E';
    else
     return 'F';
}

int main()
{
    int bangla, english, math, physics, chemistry, biology;
    float average;

    printf("Enter marks for Bangla: ");
    scanf("%d", &bangla);
    printf("Enter marks for English: ");
    scanf("%d", &english);
    printf("Enter marks for Mathematics: ");
    scanf("%d", &math);
    printf("Enter marks for Physics: ");
    scanf("%d", &physics);
    printf("Enter marks for Chemistry: ");
    scanf("%d", &chemistry);
    printf("Enter marks for Biology: ");
    scanf("%d", &biology);

    int totalMarks = bangla + english + math + physics + chemistry + biology;
    average = totalMarks / 6.0;

    printf("\nMarks Summary:\n");
    printf("Bangla: %d Grade: %c\n", bangla, calculateGrade(bangla));
    printf("English: %d Grade: %c\n", english, calculateGrade(english));
    printf("Mathematics: %d Grade: %c\n", math, calculateGrade(math));
    printf("Physics: %d Grade: %c\n", physics, calculateGrade(physics));
    printf("Chemistry: %d Grade: %c\n", chemistry, calculateGrade(chemistry));
    printf("Biology: %d Grade: %c\n", biology, calculateGrade(biology));

    printf("\nAverage Marks: %.2f\n", average);
    printf("Overall Grade: %c\n", calculateGrade((int)average));

    return 0;
}
