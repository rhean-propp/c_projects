#include<stdio.h>

int main (void) {

	char usrInpStr[40] = {"\0"};								// Array the string will be stored in.
	int titleOrCap = 0;									// Integer input from user for title case (or) capitalization.
	int wordSize = 0;									// Word size keeps track of word length.
	
	printf("\nPlease input a string with a max of 40 characters: ");    			// Instructions for user input.
	scanf(" %[^\n]s", usrInpStr);								// Gets string input from user
												// [^\n] tells scanf to end input when it sees \n
	printf("\nPress (0) for Title Case or (1) for CAPITALIZATION: ");			// Instructions for user input.
	scanf(" %d", &titleOrCap);								// Gets integer input for title case or capitalization
	
	printf("\n");										// Formatting
	
	if (titleOrCap == 0) {									// Execute if user wants to title case.
		
		for(int count = 0; count <= 40; count++) {					// Loop prints the input string out charcter by character.
			
			if (wordSize == 0) {							// New word = 0. If the character is a new word
				
				if (usrInpStr[count] >= 'a' && usrInpStr[count] <= 'z') {	// Check if lowercase.
					printf("%c", (usrInpStr[count] - 32));			// If lowercase, convert first letter to uppercase
					wordSize++;						// increase word size.
				} else if (usrInpStr[count] == ' ') { 				// Did the word end?
					printf("%c", usrInpStr[count]);				// If the word ended, print normally.
					wordSize = 0;						// If the word ended, reset wordsize to zero
				} else {							// Print character
					printf("%c", usrInpStr[count]);	
					wordSize++;						// Increase word size.
				}
				
			} else {								// If word size is greater than 0 (or) not first letter of a word.
			
				if (usrInpStr[count] >= 'A' && usrInpStr[count] <= 'Z') {	// Check if captial.
					printf("%c", (usrInpStr[count] +32));			// If capital, print as lowercase.
					wordSize++;						// Increase word size.
				} else if (usrInpStr[count] == ' ') { 				// Check if the word ended. Is there a space?
					printf("%c", usrInpStr[count]);				// Print the space normally.
					wordSize = 0;						// Reset word size for a new word.
				} else {							// Print normally.
					printf("%c", usrInpStr[count]);				// Print character.
					wordSize++;						// Increase word size.
				}
			
			}
		}
		
	} else if (titleOrCap ==1 ) {								// Execute if user wants to capitalize.
	
		for(int count = 0; count <= 40; count++) {					// Loop prints the input string out charcter by character.
			
			if (usrInpStr[count] >= 'a' && usrInpStr[count] <= 'z') {		// Checks to see if input is a lowercase ASCII character
				
				printf("%c", (usrInpStr[count] -32));				// Prints the conversion of lowercase to uppercase.
				
			} else if (usrInpStr[count] == '\0') {					// Checks to see if array element holds a NULL character
			
				break;								// If the array element is NULL, break out of the loop
			
			} else {
				printf("%c", usrInpStr[count]);					// Prints the conversion of lowercase to uppercase.
			}		
		}
	
	
	} else {
		printf("Invalid entry. Choose 0 or 1.");					// Execute if input is invalid. Give Instructions.
	}
	
	printf("\n\n");										// Formatting

	return 0;
}