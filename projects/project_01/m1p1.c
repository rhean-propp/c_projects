#include<stdio.h>

int main () {

	int userInput, inputTracker, numberOfInputs;				// Declare variables
	float average, sum;							// Declare variable
	
	sum = 0;								// Set variable value
	userInput = 0;								// Set variable value
	inputTracker = 1;							// Set variable value

	printf("\nHow many values you would like to calculate: ");		// Instructions
	scanf("%d", &numberOfInputs);						// Get number of inputs
	printf("\nInput your values below:\n\n");				// Instructions

	for (int i = 0; i < numberOfInputs; i++) {				// Initialize loop
		printf("Input #%d: ", inputTracker);				// Displays current input #
		scanf("%d", &userInput);					// Grabs input
		sum += userInput;						// Ads input to sum
		inputTracker++;							// Current input #
	}
	
	average = sum / numberOfInputs;						// Calculate average.
	printf("\nThe sum is: %.2f\n", sum);					// Display sum.
	printf("The average is: %.2f\n\n", average); 				// Display average

	return 0;
}