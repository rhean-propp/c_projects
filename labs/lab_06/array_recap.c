#include<stdio.h>

#define SIZE 20         // This will represent the size of my array which I can change in one spot and have replicated throughout my program.

int main(void) {

    int offset;
    char inputChr[SIZE] = {'\0'};

    printf("Please enter a string: ");
    scanf(" %[^\n]s", inputChr);

    for (int offset = 0; offset < SIZE; offset++) {

        if (inputChr[offset] >= 'z' && inputChr[offset] <= 'a') {
            
            // Make uppercase

        }

    }


    return 0;
}