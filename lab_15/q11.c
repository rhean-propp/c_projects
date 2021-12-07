#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

    // Store string arguments from the command line input into integer variables.
    // Store & Identify Inputs
    // Create a loop based on the inputs.
    // Check if PairXXX_01.txt exists in the directory. (Read file. If file is not read, do not count.)
    // Keep a ticker / tracker for how many files and how many pairs there are.
    // End loop
    // Print the output of the trackers.

int main (int argc, char *argv[])
{
    char array1[15] = {'\0'};   // Holds the name of the file name.
    char array2[15] = {'\0'};   // Holds the name of the file name.
    int pair = 0;
    int fileCount = 0;
    
    FILE *ptr3 = fopen("log.txt", "w");

    int beginning = atoi(argv[3]);
    int end = atoi(argv[5]);

    for(int i = beginning; i <= end; i++)
    {
        sprintf(array1, "Pair%d_01.txt", i);        // Stores the name of the file
        sprintf(array2, "Pair%d_02.txt", i);        // Stores the name of the file

        FILE *ptr1 = fopen(array1, "r");
        FILE *ptr2 = fopen(array2, "r");

        if(ptr1)
            fileCount++;

        if(ptr2)
            fileCount++;

        if(ptr1 && ptr2)
        {
            pair++;
            fprintf(ptr3, "%s exists -- %s exists", array1, array2);
        }

        fclose(ptr1);       // Close the opened file.
        fclose(ptr2);       // Close the opened file.
    }

    fclose(ptr3);

    printf("Found %d pairs of files - total file count = %d", pair, fileCount);

    return 0;
}
