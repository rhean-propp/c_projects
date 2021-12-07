#include<stdio.h>

 

// Passing is in essence feeding the value to the function
// Pass the value, you are providing the value to the function

 

void fun1(int val1, int val2)
{
    printf("val1: %d + val2: %d = %d\n",val1, val2, val1 + val2);
}

 

char fun2(char val1, char val2)
{
    if(val1 <= 'a' || val1 >= 'z')
    {
        if(val2 >= 'a' && val2 <= 'z')
            return val2;
        else
            return val1;
    }
    return val1;
}

 


void main()
{
    int val = 200;
    fun1(100, val);
    char value2;
    
    value2 = fun2('A', 'm');
    if(value2 != 'm')
        printf("There was an error\n");
    printf("%c\n", value2);
    
}