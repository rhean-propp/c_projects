#include<stdio.h>

void main() {

    int array[] = {100,2,3,4,5,6,7,80};
    int *ptr = array;

    printf("%p --- %p --- %p\n", ptr, array, &array[0]); // Prints the address of the array 3 different ways. When printing the pointer, you don't need the *

    printf("%d --- %d\n", *ptr, array[0]); // Prints the stored value.

    printf("%d\n", *ptr);

}