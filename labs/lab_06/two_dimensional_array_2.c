#include<stdio.h>

#define ROW 4         // This will represent the size of my array which I can change in one spot and have replicated throughout my program.
#define COL 20

int main(void) {

    // Challenge: 
    // Change the code so that the random values will be in the range 1-20 inclusive.
    // 1-20 inclusive
    
    char array[ROW][COL] = {'\0'};
    int row, col;
    
    srand(time(NULL));

    for(row = 0; row <ROW; row++) {

        for(col = 0; col < COL; col++) {

            array[row][col] = (rand() % 20)+1; // Added the ()+1 to complete the challenge

        }

    }

    for(row = 0; row <ROW; row++) {

        for(col = 0; col < COL; col++) {

            printf("array[%d][%d]: %d\n", row, col, array[row][col]);

        }

    }

    return 0;
}