#include<stdio.h>

int main (void) {

	char inputString[40];		// User input
	char reverseString[40];		// reverse of user input
	int index = 0;			// Incrementor for reverseString
	int stringLength = 0;		// Length of the string
	int wordSize = 0;		// Word size keeps track of word length.
	
	printf("\nEnter a sentence:  ");	// Instructions
	scanf(" %[^\n]s", inputString);		// Get input

	// Count the length of the string
	
	for (int count = 0; count < 40; count++) {		// Loops the length of the array
		if (inputString[count] == '\0')			// If the character is a NULL terminator
			break;					// Break out of the loop
		else						// If the character is not NULL
			stringLength++;				// Increment string length by 1.
	}
	
	for (int count = stringLength-1; count > -1; count--, index++) {	// Count & stringlength must be set to -1 otherwise loop breaks
		reverseString[index] = inputString[count];			// Copies and reverses user input
	}
	
	printf("Reversed Sentence: ");	// Formatting
	
	// Title Case the String
	
	for(int count = 0; count < stringLength; count++) {					// Prints string one character at a time.
		if (wordSize == 0) {								// New word = 0. If the character is a new word
			if (reverseString[count] >= 'a' && reverseString[count] <= 'z') {	// Check if lowercase.
				printf("%c", (reverseString[count] - 32));			// If lowercase, convert first letter to uppercase
				wordSize++;							// increase word size.
			} else if (reverseString[count] == ' ') { 				// Did the word end?
				printf("%c", reverseString[count]);				// If the word ended, print normally.
				wordSize = 0;							// If the word ended, reset wordsize to zero
			} else {								// Else
				printf("%c", reverseString[count]);				// Print character
				wordSize++;							// Increase word size.
			}
		} else {									// If word size is greater than 0
			if (reverseString[count] >= 'A' && reverseString[count] <= 'Z') {	// Check if captial.
				printf("%c", (reverseString[count] +32));			// If capital, print as lowercase.
				wordSize++;							// Increase word size.
			} else if (reverseString[count] == ' ') { 				// Check if the word ended. Is there a space?
				printf("%c", reverseString[count]);				// Print the space normally.
				wordSize = 0;							// Reset word size for a new word.
			} else {								// Print normally.
				printf("%c", reverseString[count]);				// Print character.
				wordSize++;							// Increase word size.
			}
		}
	}
	
	printf("\nLength: %d\n\n", stringLength);	// Print the string length
	
		
	return 0;
}