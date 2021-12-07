#include<stdio.h>

#define ROW 5
#define COL 5

int main(void) {

    int nums[ROW][COL] = {
        {1, 2, 3, 4, 5},
        {20, 30, 40, 50, 60},
        {100, 200, 300, 400, 500},
        {12, 13, 14, 15, 16},
        {0, 0, 0, 0, 0}
        };

    for(int row = 0; row < ROW; row++) {

        for (int col = 0; col < COL; col++) {

            printf("%d\t", nums[row][col]);

        }

        printf("\n");

    }

    printf("\n\n");

    return 0;
}