#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>

// Take Home Quiz #1 Problem #1

// Prototypes
void getInput(char *input);                                                // Gets Input from user.
int checkDictionary(char dictionary[100][20], char *input, int rows);      // Check to see if user input is already in the dictionary.
void insertWord(char dictionary[100][20], char *input, int rows);          // Append the word to the dictionary.
char anotherWord(char confirmation);                                       // Checks to see if user wants to enter another word.
void printDictionary(char dictionary[100][20], int rows);                  // Prints the dictionary for the user.

void main() {

    char dictionary[100][20] = {{"Around"}, {"Pool"}, {"LifeGuard"},{"Strangers"},{"Ordered"},{"Marbles"}, {"Somewhere"}, {"Futuristic"}, {"Unrealistic"}, {"Definition"}, {"Surprise"},{'\0'}};   // Declare initial dicionary words.
    char input[20] = {'\0'};        // User input is stored here. // Add this back if the declaration in insertWord()
    char confirmation = {'y'};      // Used for asking the user if they would like to add another word.
    int rows = 0;                   // Number of rows in the 2D Dictionary Array
    
    while (rows <= 100 && confirmation == 'y') {            // Loops until there are more than 100 words in the dictionary.
        getInput(input);                                    // Get input from user.
        rows = checkDictionary(dictionary, input, rows);    // Check if the word is in the dictionary
        confirmation = anotherWord(confirmation);           // Asks the user if they would like to add another word.
    }

    printDictionary(dictionary, rows);                  // Prints the dictionary for the user to read.
}

void getInput(char *input) {                            // Gets input from user.

    int exit2021 = 1;

    printf("\nAppend a word to the dictionary. Type 2021 to quit: ");                   // Prompt user.
    scanf(" %[^\n]s", input);                                                           // Get input

    exit2021 = strcasecmp(input, "2021");                                               // Checks to see if user inputted 2021.
        
    if(exit2021 == 0)                                                                   // If user inputted 2021
        exit(-1);                                                                       // Exit program
}

int checkDictionary(char dictionary[100][20], char *input, int rows) {

    int foundWord = 0;                                              // foundWord is a flag indicating the word has been found in the dictionary.
    
    rows = 0;                                                       // Resets rows for each time the function is called.

    for(int flag = 0; dictionary[rows][0] != '\0'; rows++) {        // Counts how many words are in the dictionary.
        
        flag = strcasecmp(dictionary[rows], input);                 // Compares strings irrespective of case.
        
        if (flag == 0)                                              // If there is a word in the dictionary that is the same
            foundWord = rows;                                       // Set foundWord equal to the row at the time it is discovered. 
    }

    if (foundWord > 0)                                                                          // If the foundWord in dictionary flag is set off
        printf("\nThis word is already in the dictionary stored at row %d. ", foundWord);       // Inform user the word already exists. Print the row the word is stored at.
    else {                                                                                      // If the word was not found in the dictionary
        insertWord(dictionary, input, rows);                                                    // Append the word to the dictionary.
    }

    return rows;                                                                                // Returns rows to main.
}

void insertWord(char dictionary[100][20], char *input, int rows) {      // Appends a word onto the dictionary.

    strcpy(dictionary[rows], input);                                    // Appends user input onto the dictionary.

    printf("\nWord added. ");                                           // Confirm the word has been added to the dictionary.
}

char anotherWord(char confirmation) {                                   // Asks user if they would like to append another word.
    printf("Would you like to add another word? y/n\nInput: ");         // Prompt user.
    scanf(" %c", &confirmation);                                        // Get input

    return confirmation;                                                // Return the user's answer to main.
}

void printDictionary(char dictionary[100][20], int rows) {              // Print the dictionary of words.
    
    printf("\nDictionary Word List:\n\n");                              // Formatting

    for(int count = 0; count <= rows && count <= 100; count++)          // Iterate through each row
        printf("Word %d: %s\n", count, dictionary[count]);              // Print each row line-by-line
}