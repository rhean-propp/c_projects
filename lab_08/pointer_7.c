#include<stdio.h>
 
void fun(char *ptr, char arr[][10])
{
    printf("Please enter a string: ");
    scanf(" %s", ptr);
 
    printf("%s %c\n", ptr, *ptr);
    printf("%s %c\n", arr[0], arr[0][0]);
}
 
int main()
{
    char arr[2][10] = {"Good", "Help"};
 
    fun(arr[0], arr);
    fun(arr[1], arr);
 
    return 0;
}