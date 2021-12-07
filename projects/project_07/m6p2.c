#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>

void conversion(int argc, char*argv[], char cmdInput[20][100]);                                                                                                         // Converts argv into a 2D array (cmdInput).
void variableScan(int argc, char cmdInput[20][100], int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[5]);                          // Stores cmd line arguments into their own variables
void modeSelect(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[5], char range[20][100], int *rangeLengthPtr);                    // Calls read or write depending on the mode.
void errorCheck(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[3], int bFlag, int eFlag, int sFlag, int fFlag, int mFlag);       // Checks for errors inputted by the user.
void createRange(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char range[20][100], int *rangeLengthPtr);                                                     // Creates the range specified by the user. Stores in a 2D arary.
void write(char fileName[100], char range[20][100], int *rangeLengthPtr);                                                                                               // Writes values from range into a file.
void read(char fileName[100], char range[20][100], int *rangeLengthPtr);                                                                                                // Reads a pre-existing file.


int main(int argc, char *argv[])        // argc counts how many arguments are passed. argv stores each argument from the cmd line.
{
    int rangeStart = 0;                 // Stores the start of the range. Set to 0 as default.
    int rangeEnd = 0;                   // Stores the end of the range. Set to 0 as default.
    int stepSize = 0;                   // Stores the step size. Set to 0 as default.
    int rangeLength = 0;                // Stores the length of the range.

    int *rangeStartPtr = &rangeStart;       // Pointer to value of range start.
    int *rangeEndPtr = &rangeEnd;           // Pointer to value of rangeEnd.
    int *stepSizePtr = &stepSize;           // Pointer to value of stepSize.
    int *rangeLengthPtr = &rangeLength;     // Pointer to value of rangeLength

    char fileName[100] = {'\0'};            // Stores the name of the file.
    char mode[3] = {'\0'};                  // Stores the selected read/write mode.
    
    char cmdInput[20][100] = {'\0'};        // Stores command line inputs from argv.
    char range[20][100] = {'\0'};           // Stores the calculated range of variables.

    conversion(argc, argv, cmdInput);                                                               // Converts argv into a 2D array for manipulation.
    variableScan(argc, cmdInput, rangeStartPtr, rangeEndPtr, stepSizePtr, fileName, mode);          // Stores cmd line arguments into their own variables
    modeSelect(rangeStartPtr, rangeEndPtr, stepSizePtr, fileName, mode, range, rangeLengthPtr);     // Selects read or write according to the mode.

    return 0;
}

void conversion(int argc, char *argv[], char cmdInput[20][100])     // Converts argv into a 2D array. This lets us manipulate the data without buffer overflows.
{
    for (int i = 1; i < argc; i++)                                  // Cycle through each string inside argv
        strcpy(cmdInput[i-1], argv[i]);                             // Copy argv into cmdInput one string at a time.
}

void variableScan(int argc, char cmdInput[20][100], int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[3])       // Store cmd arguments into their own variables.
{
    int bFlag = 0;      // Indicates if there is a rangeStart value.
    int eFlag = 0;      // Indicates if there is a rangeEnd value.
    int sFlag = 0;      // Indicates if there is a stepSize value.
    int fFlag = 0;      // Indicates if there is a fileName value.
    int mFlag = 0;      // Indicates if there is a mode value.

    for (int i = 0; i < argc; i++)                                  // Iterate through cmdInput.
    {  
        if (strcmp(cmdInput[i], "-b") == 0)                         // If -b is encountered:
        {
            *rangeStartPtr = strtol(cmdInput[i+1], NULL, 10);       // Store the value after -b into rangeStart.
            bFlag++;                                                // Indicate that -b was encountered.
        }    
        if (strcmp(cmdInput[i], "-e") == 0)                         // If -e is encountered:
        {
            *rangeEndPtr = strtol(cmdInput[i+1], NULL, 10);         // Store the value after -e into rangeEnd.
            eFlag++;                                                // Indicate that -e was encountered.
        }
        if (strcmp(cmdInput[i], "-s") == 0)                         // If -s is encountered:
        {
            *stepSizePtr = strtol(cmdInput[i+1], NULL, 10);         // Store the value after -s into stepSize.
            sFlag++;                                                // Indicate that -s was encountered.
        }
        if (strcmp(cmdInput[i], "-f") == 0)                         // If -f is encountered:
        {
            strcpy(fileName, cmdInput[i+1]);                        // Store the value after -f into fileName.
            fFlag++;                                                // Indicate that -f was encountered.
        }
        if (strcmp(cmdInput[i], "-m") == 0)                         // If -m is encountered:
        {
            strcpy(mode, cmdInput[i+1]);                            // Store the value after -m into mode.
            mFlag++;                                                // Indicate that -m was encountered.
        }
    }
    errorCheck(rangeStartPtr, rangeEndPtr, stepSizePtr, fileName, mode, bFlag, eFlag, sFlag, fFlag, mFlag);     // Check if user made any input errors.
}

void createRange(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char range[20][100], int *rangeLengthPtr)       // Creates the range specified by the user. Stores in a 2D arary.
{
    int *num = rangeStartPtr;                                   // Stores the stepSizePtr as it increments.
    char stringNum[100];                                        // Temporarily stores a numerical string.
    
    for (int i = 0; *rangeStartPtr <= *rangeEndPtr; i++)        // Iterates through the defined range.
    {
        sprintf(stringNum, "%d", *rangeStartPtr);               // Converts rangeStartPtr into a string and temporarily stores it in stringNum.
        strcpy(range[i], stringNum);                            // Copies the stringNum string into the 2D range array.
        *num += *stepSizePtr;                                   // increases *num by the stepSizePtr each iteration of the loop.
        (*rangeLengthPtr)++;                                    // Increment the length of the range by 1.
    }
}

void modeSelect(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[3], char range [20][100], int *rangeLengthPtr)        // Execute write() or read() based on chosen mode.
{
    if (strcmp(mode, "w") == 0)                                                             // If write mode is chosen:
    {
        createRange(rangeStartPtr, rangeEndPtr, stepSizePtr, range, rangeLengthPtr);        // Create the range with the given parameters.
        write(fileName, range, rangeLengthPtr);                                             // Write the created range to a file.
    }
    if (strcmp(mode, "r") == 0)                                                             // If read mode is chosen:
        read(fileName, range, rangeLengthPtr);                                              // Read the file.
}

void errorCheck(int *rangeStartPtr, int *rangeEndPtr, int *stepSizePtr, char fileName[100], char mode[3], int bFlag, int eFlag, int sFlag, int fFlag, int mFlag)        // Checks for input errors made by the user.
{
    if (bFlag == 0 && strstr(mode, "w") != NULL)                            // If rangeStart doesn't exist when write mode is selected.
    {
        printf("[ERROR] rangeStart value is missing.\n");                   // Indicate error
        exit (-1);                                                          // Quit program.
    }
    if (eFlag == 0 && strstr(mode, "w") != NULL)                            // If the rangeEnd doesn't exist when write mode is selected.
    {
        printf("[ERROR] rangeEnd value is missing.\n");                     // Indicate error
        exit (-1);                                                          // Quit program.
    }       
    if (sFlag == 0 && strstr(mode, "w") != NULL)                            // If stepSize doesn't exist when write mode is selected.
    {
        printf("[ERROR] stepSize value is missing.\n");                     // Indicate error
        exit (-1);                                                          // Quit program.
    }
    if (fFlag == 0)                                                         // If the fileName doesn't exist.
    {   
        printf("[ERROR] fileName value is missing.\n");                     // Indicate error
        exit (-1);                                                          // Quit program.
    }
    if (mFlag == 0)                                                         // If the mode doesn't exist.
    {
        printf("[ERROR] mode value is missing.\n");                         // Indicate error
        exit (-1);                                                          // Quit program.
    }
    if (*rangeStartPtr > *rangeEndPtr && strstr(mode, "w") != NULL)         // If rangeStart is greater than rangeEnd
    {
        printf("[ERROR] rangeStart is larger than rangeEnd.\n");            // Indicate error
        exit(-1);                                                           // Quit program.
    }
    if (*stepSizePtr >= *rangeEndPtr && strstr(mode, "w") != NULL)          // If the stepSize is greater than rangeEnd
    {
        printf("[ERROR] stepSize must be less than than rangeEnd.\n");      // Indicate error
        exit(-1);                                                           // Quit program.
    }
    if(strstr(fileName, ".txt") == NULL)                                    // If ".txt" does not exist in the fileName
    {
        printf("[ERROR] fileName must end in \".txt\".\n");                 // Indicate error
        exit(-1);                                                           // Quit program.
    }
    if (strcmp(mode, "w") != 0 && strcmp(mode, "r") != 0)                   // If the mode is neither r or w.
    {
        printf("[ERROR] Incorrect value entered for mode.\n");              // Indicate error
        exit(-1);                                                           // Quit program.
    }
}


void write(char fileName[100], char range[20][100], int *rangeLengthPtr)        // Create and write to a file.
{
    FILE *fileptr;                                                              // Declar *fileptr as a file.
                                                                                // If the file does not exist, create one. If it does exist, overwrite the existing contents.
    if ((fileptr = fopen(fileName,"w")) == NULL)                                // Open the file in writing mode. Name it with the string stored in fileName If fileptr did not open to write:
    {
        printf("[ERROR] Opening File\n");                                       // Print error.
        exit(-1);                                                               // Program exits if the file pointer returns NULL.
    }

    for (int i = 0; i < *rangeLengthPtr; i++)                                   // Cycle through each element in the range array.
        fprintf(fileptr, "%s ", range[i]);                                      // Print each element to the file.

    fclose(fileptr);                                                            // Close the file.
}

void read(char fileName[100], char range[20][100], int *rangeLengthPtr)     // Reads the pre-existing file.     
{
    FILE *fileptr;                                      // Declares *fileptr as a file.

    char c;                                             // Stores temporary character.
                                                        // If the file does not exist, create one. If it does exist, overwrite the existing contents.
    if ((fileptr = fopen(fileName,"r")) == NULL)        // Open the file in writing mode. Name it with the string stored in fileName If fileptr did not open to write:
    {
        printf("[ERROR] Opening File\n");               // Print error.
        exit(-1);                                       // Program exits if the file pointer returns NULL.
    }

    while ((c = fgetc(fileptr)) != EOF)     // Loop until the end of the file.
        putchar(c);                         // Print the character to output at each iteration of the loop.
    
    printf("\n");                           // Formatting

    fclose(fileptr);                        // Close the file.
}
