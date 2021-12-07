#include<stdio.h>

void mystrcpy(char *dest, char*src) {

    int count = 0;

    while (*src != '\0') {
        //dest[count] = *src;
        //count++;
        //src++; // src = base_address + count * sizeof(char)
        // *(src++); can also be written this way.

        *(dest++) = *(src++);
    }

    *dest = '\0';

}

void printout (char *first, char *second) {
    
    printf("String1: %s String2: %s\n", first, second);

}

void main() {

    char arr1[30], arr2[30];

    printf("Please enter a string: ");
    scanf(" %[^\n]s", arr1);

    mystrcpy(arr2, arr1);     // mystrycpy(destination, source);

    printout(arr1, arr2);

}