#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 

#define ROW 10
#define COL 10

 

void printdata(void);     // Prototype has return type, function name, parameter list
                            // parameters list contains data types

 

int main()
{
    srand(time(NULL));    // srand is seeding the random number generation process, with time(NULL);
                        // time(NULL) is a function that gets the current time in seconds from the epoch Jan 1, 1970
                        
    printdata();    // Function CALLS have --> name of the function and arguments to that function
                                        // argument lists do NOT contain the data types of the variable

 

    return 0;    
}

 

void printdata(void)
{
    int col = 0, row = 0;
    for(row = 0; row < ROW; row++)
    {
        for(col = 0; col < COL; col++)
        {
            printf("%3d ", rand() % 100);            
        } 
        printf("\n");
    }

 

}