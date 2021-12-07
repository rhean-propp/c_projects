#include<stdio.h>

void fun1(char *ptr) {
    ***********************ptr = 'B';
}

int main() {

    char var = 'A';

    printf("var: %c\n", var);
    fun1(&var);
    printf("var: %c\n", var);

    return 0;
}