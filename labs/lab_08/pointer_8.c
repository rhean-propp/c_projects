#include<stdio.h>

int main() {

    char *array[10] = {"hello", "goodbye", "welcome"};

    for(int count = 0; count < 10; count++)
        printf("%d --> %s\n", count+1, array[count]);

    return 0;
}