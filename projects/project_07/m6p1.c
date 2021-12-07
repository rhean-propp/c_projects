#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>

// TO DO:
// ---------------
// Do I need to alter the subtraction function to satisfy the assignment requirements?

void conversion(int argc, char*argv[], char cmdInput[20][100]);         // Converts argv into a 2D array. This program will manipulate the 2D array instead of argv.
void operatorScan(int argc, char cmdInput[20][100]);                    // Scans for operators. Executes the command line arguments based off BEDMAS
void multiplication(char *multiplier, char *multiplicand);              // Multiplies a string.
void addition(char *augend, char *addend);                              // Adds to a string.
void subtraction(char *minuend, char *subtrahend);                      // Subtracts from a string.
void updateArray(int argc, char cmdInput[20][100], int currentOp);      // Updates cmdInput to shift all values to the left after a completed operation.
void printOutput(int argc, char cmdInput[20][100]);                     // Prints the output of the program.

int main(int argc, char *argv[])            // argc counts how many arguments are passed. argv stores each argument in the array.
{
    char cmdInput[20][100] = {'\0'};        // cmdInput is where we will store command line inputs from argv.

    conversion(argc, argv, cmdInput);       // Converts argv into a 2D array for manipulation.
    operatorScan(argc, cmdInput);           // Scans for operators in argv. If found, execute the operation.
    printOutput(argc, cmdInput);            // Prints altered argv.

    return 0;
}

void conversion(int argc, char *argv[], char cmdInput[20][100])     // Converts argv into a 2D array. This lets us manipulate the data without buffer overflows.
{
    for (int i = 1; i < argc; i++)                                  // Cycle through each string inside argv
        strcpy(cmdInput[i-1], argv[i]);                             // Copy argv into cmdInput one string at a time.
}

void operatorScan(int argc, char cmdInput[20][100])                     // Scans for operators. Executes the command line arguments based off BEDMAS
{
    int multiplyFlag = 0;                                               // Stores the number of asterisk (*) signs found in cmdInput .
    int plusFlag = 0;                                                   // Stores the number of plus (+) signs found in cmdInput.
    int minusFlag = 0;                                                  // Stores the number of minus (-) signs found in cmdInput.
    int currentOp = 0;                                                  // Stores the location of the current operator from cmdInput.

    for (int i = 0; i < argc; i++)                                      // Check what operators are stored in cmdInput
    {  
        if (*cmdInput[i] == '*')                                         // If an asterisk sign is encountered:
            multiplyFlag++;                                             // Increase asterisk by 1.
        if (*cmdInput[i] == '+')                                        // If a plus sign is encountered:
            plusFlag++;                                                 // Increase plus sign by 1.
        if (*cmdInput[i] == '-')                                         // If a minus sugn is encountered:
            minusFlag++;                                                // Increase minus sign by 1.
    }

    while (multiplyFlag > 0)                                            // While there is more than 1 asterisk(s).
    {
        for (int i = 0; i < argc; i++)                                  // Cycle through each string in cmdInput.
        {  
            if (*cmdInput[i] == '*')                                    // If an asterisk is encountered.
            {
                multiplication(cmdInput[i-1], cmdInput[i+1]);           // Pass the value before and after the asterisk into the multiplication function.
                multiplyFlag--;                                         // Decrement the amount of asterisk signs encountered by 1.
                currentOp = i;
                updateArray(argc, cmdInput, currentOp);
            }
        }                                                  
    }
    
    while (plusFlag > 0)                                                // While there is more than 1 plus sign.
    {
        for (int i = 0; i < argc; i++)                                  // Cycle through each string in cmdInput
        {  
            if (*cmdInput[i] == '+')                                    // If a plus sign is encountered.
            {
                addition(cmdInput[i-1], cmdInput[i+1]);                 // Pass the value before and after the plus sign into the addition function.
                plusFlag--;                                             // Decrement the amount of plus signs encountered by 1.
                currentOp = i;
                updateArray(argc, cmdInput, currentOp);
            }
        }
    }

    while (minusFlag > 0)                                               // While there is more than 1 minus sign.
    {
        for (int i = 0; i < argc; i++)                                  // Cycle through each string in cmdInput.
        {  
            if (*cmdInput[i] == '-')                                    // If a minus sign is encountered.
            {
                subtraction(cmdInput[i-1], cmdInput[i+1]);              // Pass the value before and after the minus sign into the subtraction function.
                minusFlag--;                                            // Decrement the amount of plus signs encountered by 1.
                currentOp = i;
                updateArray(argc, cmdInput, currentOp);
            }
        }
    }
}

void multiplication(char *multiplier, char *multiplicand)           // Multiplies a string by a specified number.
{                      
    long int valueOfString = strtol(multiplicand, NULL, 10);        // Extract the number(s) from the string and convert them into an long integer.
    char temp[100] = {'\0'};                                        // Temporary variable to store the strcat of multiplier

    for (int j = 0; j < valueOfString; j++)                         // Cycle through the number entered by the user. After the asterisk (*)
        strcat(temp, multiplier);                                   // Append the string to the temporary variable each time the loop cycles.               
    
    strcpy(multiplier, temp);                                       // Copy the result of the loop into multiplier to save it to cmdInput.
}

void addition(char *augend, char *addend)       // Append two strings together.
{
    strcat(augend, addend);                     // Append addend to augend. Save to cmdInput.
}

void subtraction(char *minuend, char *subtrahend)           // Subtracts one string from another.
{
    char *canSubtract = strstr(minuend, subtrahend);        // Determines if the minuend can be subtracted by the subtrahend.
    int minLength = strlen(minuend);                        // Get the string length of the minuend. (Value before the minus (-) symbol.)
    int subLength = strlen(subtrahend);                     // Get the string length of the subtrehend. (Value after the minus (-) symbol.)

    char *temp = minuend;                                   // Sets temp to the minuend. Allowing us to modify the minuend without breaking it.

    if (temp = strstr(temp, subtrahend))                    // Compares temp(minuend) with subtrahend. If subtrahend is found in temp(minuend), store the value from strstr into temp.
    {                                                       // If the subtrahend was found in the minuend, the if statement will execute, since the condition is true.
        *temp = '\0';                                       // At the first occurence of the subtrahend within the temp(minuend), set the character to NULL.
        strcat(minuend, temp+subLength);                    // Add the length of the subtrahend to temp(minuend with NULL terminator). Append the remaining letters (starting from the NULL) to minuend.
    }
}

void updateArray(int argc, char cmdInput[20][100], int currentOp)
{
    char tempArray[20][100] = {'\0'};                               // Temporary array to store cmdInput

    for (int i = 0; i < argc; i++)                                  // Cycle through cmdInput
        strcpy(tempArray[i], cmdInput[i]);                          // Copy cmdInput into tempArray

    for (; currentOp < argc; currentOp++)                           // Cycle through cmdInput starting at the current operator.
        strcpy(cmdInput[currentOp], tempArray[currentOp+2]);        // Copy the temporary array into cmdInput starting from the next operator in the expression.
}

void printOutput(int argc, char cmdInput[20][100])      // Prints the output of cmdInput
{
    printf("%s\n", cmdInput[0]);                        // Print each element of the array.
}