#include<stdio.h>

int fact1(int num) {
    
    int result = 1;
    
    for(int count = 1; count <= num; count++)
        result *= count;

    return result;
}

int fact2(int num) {

    if(num == 0)
        return 1;
    else
        return fact2(num-1) * num;
}

int main() {

    int num;
    printf("Enter a number for factorial: ");  
    scanf("%d", &num);

    printf("Factorial of num: %d\n", fact1(num));
    printf("Factorial of num: %d\n", fact2(num));

    return 0;
}