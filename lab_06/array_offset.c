#include<stdio.h>

#define SIZE 20         // This will represent the size of my array which I can change in one spot and have replicated throughout my program.

int main(void) {

    int offset;
    char input[SIZE] = {'\0'};

    printf("Please enter a string: ");
    scanf(" %[^\n]s", input);

    for (offset = 0; offset < SIZE; offset++) {

        printf("%s = %c = %x\n", input, input[offset], input[offset]);

    }


    return 0;
}