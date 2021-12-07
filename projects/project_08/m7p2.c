#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char getInput(char input, char filename[]);                                         // Gets a character. Converts the char to uppercase.
char createFile(FILE *namesPtr, FILE *sortPtr, char input, char filename[]);        // Creates a file based off user input.

int main()
{
    char input = {'\0'};            // Declare a 1D array to store the input character.
    char filename[11] = {'\0'};     // Stores the file name based off the users input.

    input = getInput(input, filename);              // Get input from the user. Filename is passed as pointer. (array)

    FILE *namesPtr = fopen("names.txt", "r");       // Open the names.txt file for reading.
    FILE *sortPtr = fopen(filename,"a+");           // Open the [%c]names.txt for appending.

    if (!namesPtr || !sortPtr)                                      // Check if the files opened correctly.
    {
        printf("One of the files did not open correctly.\n");       // Print error message.
        exit(-1);                                                   // Quit program.
    }

    createFile(namesPtr, sortPtr, input, filename);     // Creates a file based off user input.
 
    fclose(namesPtr);       // Closes the source file.
    fclose(sortPtr);        // Closes the new file.

    return 0;
}

char getInput(char input, char filename[])              // Creates a file based off user input.
{
    printf("Enter the first letter of a name: ");       // Give user instructions.
    scanf(" %c", &input);                               // Get input from user.

    if(input >= 61)             // If the input is lowercase.
        input = input- 32;      // Turn it into uppercase.
    
    sprintf(filename, "%cnames.txt", input);     // Copy user input to the first element of filename and append names.txt to the rest of the string.

    return input;       // Return the character.
}

char createFile(FILE *namesPtr, FILE *sortPtr, char input, char filename[])
{
    char buffer[30] = {'\0'};       // Stores the string from the original file.
    char compare[30] = {'\0'};      // Stores the string to be compared to the original.
    int nameCount = 0;

    while(fscanf(namesPtr, "%s", buffer) != EOF)        // Cycle through each string in the file until it reaches the end.
    {
        if(buffer[0] == input)                          // If the first character is the same as the user input.
        {
            fscanf(sortPtr, "%s", compare);             // Store the string from the new file (sortPtr) into the compare array.
            
            nameCount++;                                // Count how many names there are inside the newly created file.
            
            if(strlen(buffer) > 5)                      // If the length of the string in the new file is greater than 5
                printf("%s\n", buffer);                 // Print it to the screen.
            if(strcmp(buffer, compare) == 0)            // Check if the string from the original file is found in the new file.
                continue;                               // If the comparison is true, don't append the name to the file.
            else;                                       // If the comparison is FALSE
                fprintf(sortPtr, "%s\n", buffer);       // Append the name to the file.
        }
    }

    printf("\nThere are %d names in %s\n", nameCount,filename);     // Print the count and name of file.
}
