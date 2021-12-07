#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 31

//Prototypes
void getInput(char array[SIZE]);                // Get input from user.
void convert(char array[SIZE]);                 // Convert string to a number with an algorithym. Check if 8470.
void randChars(int number);                     // Generate a random character string
void challenge();    
void checkAnswer(char array[SIZE], int number); // Pass value from challenge to check the answer.                           

void main() {

    int loopCount = 0;
    char userInput[SIZE] = {'\0'};      // Array for user input

    srand(time(NULL));      // Seed the random number generator.

    while (1) {
        getInput(userInput);
        loopCount++;
        if (loopCount >= 3)
            exit(-1);
    }
}

void getInput(char userInput[SIZE]) {         // Get user input

    printf("Please enter a string: ");        // Instructions
    scanf(" %[^\n]s",userInput);              // Get input
    convert(userInput);
}

void convert(char userInput[SIZE]) {              // Convert user input to a number

    int stringLength = 0;                               // Start length at zero.
    int magicNumber = 0;                                // Value of input string converted to num.

    for(int count = 0; count < SIZE; count++)         // Iterate through the max size of the string.
        if (userInput[count] != '\0')                   // As long as the character is NOT NULL
            stringLength++;                             // Increase string length by one.

    for (int count = 0; count < stringLength; count++)                  // Iterate by the length of the string.
        magicNumber += userInput[count] * (stringLength - count);      // Covert string to number algorithym.                 

    if (magicNumber != 8470) {                       // If NOT 8470
        printf("Welcome, you may proceed.\n");      // Output message
        randChars(stringLength);                    // Call randChars | Output random characters
    } else                                          // If 8470
        challenge();                                // Call challenge()
}

void randChars(int stringLength) {                          // Generate and output random charactere

    char randomString[stringLength];                        // String for storing random characters

    for (int count = 0; count < stringLength; count++)      // Iterates the length of the string
        randomString[count] = rand() % 256;                 // Includes ASCII characters for randomization

    printf("%s\n\n", randomString);                         // Outputs the string.

}

void challenge() {
    
    int question = 0;                   // Value used to decide which riddle to give the user
    char riddleInput[SIZE] = {'\0'};    // User input for riddle question

    question = rand() % 3;  // Generate a random number between 0-2 inclusive.

    if (question == 0)                                                               // If 0
        printf("What has a mouth but can't speak?\n");                              // Ask riddle 0
    else if (question == 1)                                                          // If 1
        printf("The more you take, the more you leave behind. What am I?\n");       // Ask riddle 1
    else                                                                            // If 2
        printf("What has a head, a tail, is brown, and has no legs?\n");            // Ask riddle 2
    
    scanf(" %[^\n]s", riddleInput);         // Get input
    checkAnswer(riddleInput, question);     // Pass input to checkAnswer
}

void checkAnswer(char riddleInput[SIZE], int question) {

    int flag = 0;       // Flags the answer as incorrect if any character values do not match.
    
    char riddleKey [3][SIZE] = {{"river"},{"footsteps"},{"penny"}};     // Answer key

    for(int count = 0; riddleInput[count] != '\0'; count++)          // Iterate as until a NULL is encountered
        if(riddleInput[count] != riddleKey[question][count])            // If the input does not equal the answer
            flag = 1;                                                   // Flag as wrong input

    if (flag == 0) {                                            // If the flag was not set off.
        printf("Welcome IT Guru, proceed to C&C center.\n");    // Output confirmation
        exit(-1);                                               // Terminate program
    }
}