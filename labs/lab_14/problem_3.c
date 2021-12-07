#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// Offset means position relative to zero.

int main()
{
    FILE *ptr = fopen("myfile.txt", "rb");
    int offset = 0;
    unsigned char val;
    int i = 0;
    char asciiArray[16] = {'\0'};

    if(!ptr)
    {
        printf("This didn't work\n");
        exit(-1);
    }

    while(fread(&val, 1, 1, ptr))
    {
        if(21 > val > 0 || val == 127)          // If a non-printable character is read
            strcpy(&asciiArray[i], ".");        // Replace it with a period.
        else                                    // Otherwise
            strcpy(&asciiArray[i], &val);       // Store the character as it is.

        if(i == 0)                          // If the loop is at the start or has been reset
            printf("\n%06x ", offset);       // Print the offset.

        i++;        // Inciment the loop by 1. 

        if(i == 16)     // If 16 characters have been printed
            i = 0;      // Reset the loop.

        if (i == 9)             // If the byte being read is halway through the hex dump
            printf(" ");        // Print a space.
        
        
        printf("%02x ", val);       // Print the hexedimal value.

        if (i == 0)     // If the loop has been reset.
        {
            printf("|");                            // Begin formatting ascii
            
            for (int j = 0; j < 16; j++)            // Iterate 16 times.
                printf("%c", asciiArray[j]);        // Print each ascii character one at a time.
            
            printf("|");                            // End formatting ascii.

            for (int j = 0; j < 17; j++)            // Iterate 17 times.
                asciiArray[j] == '\0';              // Clear the array and replace it with NULL characters.
        }
        
        offset++;                                    // Increase the offset by 1.
    }

    printf("\n\nDone!!!\n");
    fclose(ptr);
}