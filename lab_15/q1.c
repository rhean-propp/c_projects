#include<stdio.h>

#define ROW 10
#define COL 20
 
int main()
{
    char argv[ROW][COL] = {"This is ", "not fun ", 
                           "lots of fun ", "why", 
                           "why not", "do this ", 
                           "make this ", "yearly ", 
                           "daily ", "HUH!!!"};
 
    for(int count = 0; count < ROW; count += 2)
        printf("[line:%2d] -> %s",argv[count]);     // Missing the second argument for the string.
    
    return 0;
}
