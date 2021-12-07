#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getInput(char input[]);                // Grab the filename + extension from the user.
void hexDump(FILE *ptr);                    // Output the hexdump of the file.
void magicNumber(FILE *ptr);                // Output the magic number of the file.
void fileType(int garbage, int offset);     // Output the type of file being read.

int main() 
{
    char input[15] = {'\0'};            // Stores filename & extension.
    
    getInput(input);                    // Grab the filename + extension from the user.

    FILE *ptr = fopen(input, "rb");     // Open the file with the user input.

    if(!ptr)                                            // If the file did not open correctly:
    {
        printf("Aghast! The file did not open!\n");     // Print error
        exit(-1);                                       // Quit the program.
    }

    hexDump(ptr);       // Print out a hexdump of the file.
    fclose(ptr);        // Close the file.
}

void getInput(char input[])             // Grab the filename + extension from the user.
{
    printf("Enter a filename: ");       // Instructions
    scanf(" %s", input);                // Grab Input
}

void hexDump(FILE *ptr)                 // Output the hexdump of the file.
{
    char asciiArray[16] = {'\0'};       // Stores the ascii representation of each read hex value.
    unsigned char val;                  // Temporarily stores a hex value.
    int offset = 0;                     // Stores offset of each hex value.
    int i = 0;                           // Used for looping through 16 hex values.
    int garbage = 0;                    // Keeps track of how many ascii characters are garbage for fileType function.
    float garbageRatio = 0;             // Holds the ratio of readable to non-readable ascii characters.
    
    while(fread(&val, 1, 1, ptr))               // Loop through the file 1 byte at a time.
    {        
        if(33 > val > 0 || val >= 127)          // If a non-printable character is read
        {    
            strcpy(&asciiArray[i], ".");        // Replace it with a period.
            garbage++;                          // Increase the garbage counter by 1.
        }
        else                                    // Otherwise
            strcpy(&asciiArray[i], &val);       // Store the ascii character into the array as it is read from the file.

        if(i == 0)                              // If the loop is at the start or has been reset
            printf("\n%06x ", offset);          // Print the offset.

        i++;                                    // Inciment the loop by 1. 

        if(i == 16)                             // If 16 characters have been printed
            i = 0;                              // Reset the loop.
        
        printf("%02x ", val);                   // Print the hexedimal value

        if (i == 0)                                 // If the loop has been reset, execute ascii print.
        {
            printf("|");                            // Begin formatting ascii
            
            for (int j = 0; j < 16; j++)            // Iterate 16 times.
                printf("%c", asciiArray[j]);        // Print each ascii character one at a time.
            
            printf("|");                            // End formatting ascii.

            for (int j = 0; j < 17; j++)            // Iterate 17 times.
                asciiArray[j] == '\0';              // Clear the array and replace it with NULL characters.
        }
        
        offset++;                                   // Increase the offset by 1.
    }

    if(feof(ptr))
    {
        for(int k = 16-i; k > 0; k--)           // Cycle through the remaining sections of the array
        {
            printf("   ");                      // Print spaces to the end of the hex dump for formatting.
            strcpy(&asciiArray[16-k], ".");     // Adds a period to the ascii section for the amount of empty spaces.
        }

        printf("|");                            // Begin formatting ascii
            
        for (int j = 0; j < 16; j++)            // Iterate 16 times.
            printf("%c", asciiArray[j]);        // Print each ascii character one at a time.
            
        printf("|\n");                          // End formatting ascii.
    }
    
    fileType(garbage, offset);                  // Tell the user what type of file this might be.
    magicNumber(ptr);                           // Print the magic number of the file.
}

void magicNumber(FILE *ptr)                 // Prints the magic number of the read file.
{
    unsigned char magNum[4] = {'\0'};       // Stores the hexidecimal value for the magic number.

    rewind(ptr);                            // Rewinds the file cursor to the beginning of the file.
    fread(&magNum, 1, 4, ptr);              // Reads the first 4 bytes of the file and stores them into the magNum array.

    printf("Magic Number: 0x");             // Formatting print.

    for (int i = 0; i < 4; i++)             // Cycles through the first 4 elements of the array.
        printf("%02x", magNum[i]);          // Prints the hex value one at a time.
    
    printf("\n\n");                         // Formatting
}

void fileType(int garbage, int offset)      // Tell the user what type of file this might be.
{   
    float garbageRatio = 0;                             // Stores the ratio of garbage to offset.

    garbageRatio = (float)garbage / (float)offset;      // Calculates the ratio of garbage to offset. Stored as a decimal value between 0 and 1.
    
    if (garbageRatio < 0.25)                                // If the value is less than 25%
        printf("\nThis is a binary file.\n");               // Print Output
    else if(0.75 > garbageRatio > 0.25)                     // If the value is between 25% and 75%
        printf("\nThis is possibly a text file.\n");        // Print Output
    else if(garbageRatio > 0.75)                            // If the value is greater than 75%
        printf("\nThis is a text file.\n)");                // Print Output
}