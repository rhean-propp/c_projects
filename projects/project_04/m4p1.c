#include<stdio.h>

#define SIZE 12     // Max length of input values.

// Prototypes

void getNums(float array[]);                                // Gets user input
void sortNums(float array[], int size);                     // Saves original input & sorts user input.
void printNums(float array1[], float array2[], int size);   // Outputs both original input and user input.

int main(void) {

    float userInput[SIZE] = {'0'};      // Array used for user input.
    
    printf("Please enter %d values:\nEnter 0 to finish input stream.\n", SIZE);     // Instructions
    getNums(userInput);                                                             // Call getNums to get user input. Pass userInput array in parameters.

    return (0);
}

void getNums(float userInput[]) {       // Gets user input.

    int size = 0;                       // Keeps track of how many inputs user enters.

    for(int count = 0; count < SIZE; count++) {     // Iterates 12 (SIZE) times.

            printf("Value %d: ", count+1);          // Count begins at 0 | count+1 is used for formatting. 
            scanf(" %f", &userInput[count]);        // Get user input for each value of the 1D array.

            size = count;               // Track number of user inputs.
            if(userInput[count] == 0)   // If user input is 0
                break;                  // Break out of the loop.
    }

    sortNums(userInput, size);    // Send user input to sortNums, along with amount of inputs.

}

void sortNums(float userInput[], int size) {      // Saves original unsorted input & bubble sorts user input. 

    float ram = 0;                                // Stores a user[index] value temporarily to permit the swap to occur.
    float unsortedInput[SIZE] = {'0'};            // Stores userInput's original value before it is sorted.


    for(int count = 0; count < size; count++) {     // Loop 1 less than size. size is the amoung of entries.
        unsortedInput[count] = userInput[count];    // Save the original input.
    }


    for(int count = 0; count < size; count++) {             // Iterate size Times
                                                            // Two for loops are used so the bubble sort goes through each value enough times to order them properly.
        for(int index = 0; index < size-1; index++) {       // Iterate size-1 Times | This counter balances the index+1 in the following if statement.
                                                            // The for loop runs a total of 
            if (userInput[index] > userInput[index+1]) {    // If the value at userInput[index] is greater than the next index value
                                                            // Begin swap:
                ram = userInput[index];                     // Step 1: Temporarily store the current userInput[index] value in ram. 
                userInput[index] = userInput[index+1];      // Step 2: Update userInput[index] to the next index iteration
                userInput[index+1] = ram;                   // Step 3: Update the next index iteration with the original index iteration.
                
            }
        }

    }

    printNums(unsortedInput, userInput, size);              // Call the printNums function, pass it the two arrays we've created.
    
}

void printNums(float unsortedInput[], float userInput[], int size) {         // Print the output of our program.

    printf("\nUnsorted\tSorted\n========\t========\n");                      // Formatting

    for(int count = 0; count < size; count++) {                              // Loops size times.

        printf("%.2f\t\t%.2f\n", unsortedInput[count], userInput[count]);    // Prints unsorted values.

    }

}