#include<stdio.h>

void swap(int *ptr1, int *ptr2) {

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

}

void main () {

    int val1, val2;

    printf("Please enter 2 values: ");
    scanf(" %d %d", &val1, &val2);

    printf("val1: %d, val2: %d\n", val1, val2);

    swap(&val1, &val2); // Swaps the values

    printf("val1: %d, val2: %d\n", val1, val2);

}