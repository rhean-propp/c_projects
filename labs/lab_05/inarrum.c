[2:53 PM] Gary Rowe
    
#include<stdio.h>


int main()
{​​​​​​​
    int index, count;
    int arrInt[10];    // 4bytes * 10 elements ==> 40 bytes


    // = means assignments     a = 10; now a is assigned the value of 10
    // == means test for equality    a == 10 is testing to see if a contains 10 and if so evaluates to TRUE or 1
    for(index = 0; index < 10; index++)            // ask user for 10 numbers and store then in the array arrInt
    {​​​​​​​
        if(index ==  8)
            continue;                // continue causes the loop to increment index but instead of going to the lines below
                                    //  it jumps to the top of the loop.
        printf("Enter number %d: ", index+1);
        scanf("%d", &arrInt[index]);
    }​​​​​​​


/*
    printf("Element\t Address \t Value\n");


    for(index = 0; index < 10; index++)
    {​​​​​​​
        printf("%d \t %p \t %d", index+1, &arrInt[index], arrInt[index]);
    }​​​​​​​*/
    return 0;
}​​​​​​​






<https://teams.microsoft.com/l/message/19:ce49c435a6fe4bc9bb0012c494e96c36@thread.tacv2/1612993999984?tenantId=f52f2183-9f67-4ad2-b656-6f754fe196cb&amp;groupId=1a4b6b89-7312-42cf-b232-ea5cf332ecac&amp;parentMessageId=1610567597796&amp;teamName=ITSC202_Win21&amp;channelName=ITSC202_A&amp;createdTime=1612993999984>
