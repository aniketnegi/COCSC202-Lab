// Write a program to store the marks obtained by 10 students in 5 courses in a two-dimensional array.
#include <stdio.h>

#define STUDENTS 10
#define COURSES 5

static void print_arr(int arr[STUDENTS][COURSES]);

int main(void)
{
    int marks[STUDENTS][COURSES];

    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter the marks for Student %d\n", i+1);
        for (int j = 0; j < COURSES; j++) {
            printf("Enter marks for Course %d: ", j+1);
            scanf("%d", &marks[i][j]);
        }
    }

    print_arr(marks);

    return 0;
}

static void print_arr(int arr[STUDENTS][COURSES]) {
    // arr is a 2-D arr
    for (int i = 0; i < STUDENTS; i++) {
        printf("STUDENT %d:\n", i+1);
        for (int j = 0; j < COURSES; j++) {
            printf("\tCourse %d: %d\n", j+1, arr[i][j]);
        }
    }
}
