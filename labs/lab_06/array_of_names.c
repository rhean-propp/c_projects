#include<stdio.h>

#define ROW 20
#define COL 20

int main(void) {

    char firstname[ROW][COL];

    for (int count = 0; count < ROW; count++) {

        printf("Please enter a name");
        scanf(" %[^\n]s", &name[count][0]);
        scanf(" %[^\n]s", name[count]);
        scanf(" %[^\n]s", name[count][count]);
    }

    return 0;
}