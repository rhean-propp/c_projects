[2:28 PM] Gary Rowe
    
#include<stdio.h>


int main()
{​​​​​​​


    // offset is a value relative to the beginning of the array.
    // 0th offset - this is the first element of the array for arrInt that would be 1
    // 4th offset - This is the fifth element of the array for arrInt that would be 10
    int arrInt[] = {​​​​​​​1,23,5,25,10}​​​​​​​;            // Initializing 2 integer arrays each of 5 elements
    int arrInt2[10] = {​​​​​​​12, 42, 32, 100, 20}​​​​​​​;    
    int index, sum = 0;                            // declare and initialize index and sum respectively
    char arr2[] = "Rhean";    // {​​​​​​​'R','h','e','a','n','\0'}​​​​​​​;


    index = sizeof(arrInt)/sizeof(int);   // index = 20bytes/ 4bytes -- so index == 5
    
    for( ; index > 0; index-- )
    {​​​​​​​
        sum += arrInt[index - 1];    // sum = sum + arrInt[5-1]   --- sum = 0 + 10  ===> sum == 10
        printf("\t[DEBUG 14] sum = %d\n", sum);    // Prints a debug statement so that we can see the output at a specific stage.
        //getchar();                                // Stops program execution temporarily....
    }​​​​​​​
    printf("\n\n");
    for(index = 5; index > 0; index--)
    {​​​​​​​
        printf("\t[Debug 24] index: %d, arrInt[index-1]: %d, arrInt[index]- 1: %d\n", index, arrInt[index-1], arrInt[index] - 1);
        getchar();
    }​​​​​​​
 
    printf("Average of values in arrInt is: %.2f\n", (float) sum / (sizeof(arrInt)/sizeof(int)));


    for(index = 0; index < 10; index++)
    {​​​​​​​
        if(arrInt2[index] < 20)
        {​​​​​​​
            arrInt2[index] += (2 << (index + 1));        // arrInt2[0] = arrInt2[0] + 2<< (0+1)
                                                         // arrInt2[0] = 12 + 2 << 1
            printf("Index %d is: %d\n", index, arrInt2[index]);
        }​​​​​​​ 
        else
            printf("Index %d is: %d\n", index, arrInt2[index]);
    }​​​​​​​

	return 0;
}​​​​​​​

