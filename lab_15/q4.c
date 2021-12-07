#include<stdio.h>

void swapch(char *val1, char *val2)
{
    char temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int main()
{

    char *aval;
    char *bval;

    printf("Enter 2 chars: ");
    scanf("%c %c", &aval, &bval);
    //swapch(&aval, &bval);
    printf("%c %c\n", aval, bval);
    return 0;
}
