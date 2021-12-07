#include<stdio.h>

/*
    *(array1 + count) -> this does not move by a single byte
                      -> instead it moves by the size of the array element
                      base address + count * sizeof(datatype)
                      0x7543210    + 0      *  4
                      0x7543210    + 1      *  4
                      0x7543210    + 2      *  4
*/
int main()
{
    int array1[10] = {1,2,3,4,5,6,7,8,9,0};
    int value = 100;

 

    //  Though the below for loop is valid; to avoid confusion avoid the use of an array as a pointer.
    for(int count = 0; count < 10; count++)
    {
          printf("%d\n", *(array1 + count));  // *(array1 + count) equivalent to array1[count]
    }

 

    // The line below is not valid and makes clear that pointers and arrays are not the same.

 

    //array1 = &value;        // This is an invalid statement
    *array1 = value;        // Valid because *array is equivalent to array1[0]

 

    for(int count = 0; count < 10; count++)
        printf("%d\n", *(array1 + count)); // *array1 Valid but should be avoided

 

    return 0;
}