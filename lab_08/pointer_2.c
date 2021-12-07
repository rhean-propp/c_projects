#include<stdio.h>

void main() {

    printf("this is all about pointers\n");

    int val1 = 100;
    int *ptr2;
    ptr2 = &val1;

    int val2 = 200;

    printf("val1, %d, *ptr2: %d\n", val1, *ptr2);

    ptr2 = &val2;
    
    printf("val1, %d, *ptr2: %d\n", val1, *ptr2);

    val1 = *ptr2;

    printf("val1: %d &ptr2: %d\n", val1, *ptr2);

}
