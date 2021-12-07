#include<stdio.h>

#define COUNT 27

int main()
{
               char arr[COUNT] = "ABCDEFGHIJKLMNOPQRSTUVWZYZ";
               
               for(int count = COUNT - 2; count >= 0; count--)
               {
                              if(arr[count] == 'A' || arr[count] == 'E' || arr[count] == 'I' || arr[count] == 'Z')
                              {
                                             printf("I don't like the letter: %c\n", arr[count]);
                                             arr[count] = arr[count] + 32;
                              }
                              else
                                             arr[count] = arr[count] + 1;
                              
               }
               
               
               for (int count = 26; count >= 0; count--) {
               
               	printf("%c", arr[count]);
       
               }
               
               printf("\nAfter all the manipulation\nMy array now contains: %s\n", arr);
               
               return 0;
}

