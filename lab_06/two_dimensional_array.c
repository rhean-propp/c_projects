#include<stdio.h>

#define ROW 4         // This will represent the size of my array which I can change in one spot and have replicated throughout my program.
#define COL 20

int main(void) {

    int count;
    char students[ROW][COL] = {'\0'};

    for (count = 0; count < ROW; count++) {

        printf("Enter a student name: "); 
        // fgets(students[count], COL-1, stdin); // stdin represents the input stream to read from.
        scanf(" %[^\n]s", students[count]);  // students[count] --> is equivalent to &students[count][0]
    }

    for (count = 0; count < ROW; count++) {

        printf("students[%d]: %s\n", count, students[count]);
    }


    return 0;
}