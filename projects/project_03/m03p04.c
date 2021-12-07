#include<stdio.h>

int main (void) {

	int number[6];		// Integer array
	char letter[7];		// Character arary
	
	for (int count = 0; count < 6; count++) {			// Iterate 6 times
		printf("Enter Integer number: ");			// Give instructions
		scanf(" %d", &number[count]);				// Get integer input for number array
	}
	
	printf("\nEnter a 6 [max] letter string: ");	// Give instructions
	scanf(" %s", letter);				// Get string input for letter array
	
	printf("\nElement\t\tAddress\t\t    Hex\n==============================================\n");	// Format
	
	for (int count = 0; count < 6; count++) {						// Iterate 6 times
		printf("Number[%d]\t%p\t    Ox%x\n", count+1, &number[count], number[count]);	// Print number array, address and hex value
	}
	
	printf("==============================================\n");	// Format

	for (int count = 0; count < 6; count++) {						// Iterate 6 times
		printf("Letter[%d]\t%p\t    Ox%x\n", count+1, &letter[count], letter[count]);	// Print character array, address and hex value
	}

	printf("==============================================\n\n");	// Format

	return 0;
}