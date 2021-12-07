// Rock Paper Scissors Program

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {

	char userInput;										// Character user inputs in the terminal.
	int rock, paper, scissors;							// Variables for the refrence tables.
	int numericalUserInput;								// Comparison Value. Always = 1.
	
	numericalUserInput = 1;								// User Input will always be 1.
	
	printf("\n\tRock, Paper or Scissors? ");			// Prompt user
	scanf("%c", &userInput);							// Get input
	
	
	switch (userInput) {								// Switch Chooses a table based on user input.
	
		case 'r' : 										// Table A
		printf("\n\tYou chose rock!\n\n");
		rock = 1;
		paper = 2;
		scissors = 0;
		break;
		
		case 'p' : 										// Table B
		printf("\n\tYou chose paper!\n\n");
		rock = 0;
		paper = 1;
		scissors = 2;
		break;
		
		case 's' :										// Table C
		printf("\n\tYou chose scissors!\n\n");
		rock = 2;
		paper = 0;
		scissors = 1;
		break;
		
		default :
		printf("\n\tYour input is invalid. Use: r, p or s.\n\n");
	
	}
	
	// Random Number Generator
	// Generates between 0-2
	int random;
	srand(time(0));										// Sets the seed for the generator. Without this, number repeats.
	random = rand() % 3;								// Generates random number.
	
	
	  // Computer's Pick

      if (random == rock) {
      	printf("\tComputer picked rock!\n");
      }
      
      else if (random == paper) {
      	printf("\tComputer picked paper!\n");
      }
      
      else {
      	printf("\tComputer picked scissors!\n");
      }
      
      // Game Outcome
      
      if (random == numericalUserInput) {
			printf("\n\tTie!\n\n");      
      } 
      
      else if (random > numericalUserInput) {
      		printf("\n\tYou lose!\n\n");
      }
      
      else {
      	printf("\n\tYou win!\n\n");
      }
      
      
	return 0;
}
