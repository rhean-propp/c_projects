#include<stdio.h>

int main() 
{
    char array[7] = "aBcDeF";
    char *ptr = array;

    for(int count = 0; count < strlen(array); count+=2)
    {
        char temp = *ptr;
        *ptr = *ptr+1;
        *ptr+1 = temp;
    }
}
