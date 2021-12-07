#include<stdio.h>

#define SIZE 5

int main(void) {

    int arrayInt[SIZE] = {1, 2, 3, 4, 5};
    int arrayFlip[SIZE];
    int index = SIZE-1;

    // Print out
    for (int count = 0; count < 5; count++) {

        printf("%d", arrayInt[count]);

    }

    printf("\t");

    for (int count = 0; count < 5; count++) {

        arrayFlip[index] = arrayInt[count];
        index--;
    }

    for (int count = 0; count < 5; count++) {

        printf("%d", arrayFlip[count]);

    }

    printf("\n");

    return 0;
}