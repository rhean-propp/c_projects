#include<stdio.h>


int main (void) {

	int index = 0;
	char arrChar[] = {"Char Array"}; // A string can be considered a grouping of characters
									 // All strings in C must be terminated with the NULL (\0 character)
									 // 0 is an integer - 4 bytes
									 // \0 is a character - 1 byte
	
	while (arrChar[index] != '\0') { 	// \0 checks to see if the string is over
		
		printf("Char %d is: %c\n", index, arrChar[index]);
		index++;
	
	}
	
	printf("\nAnother one: \n");
	
	int count = 10;
	
	while(count < 20000) {
		
		printf("Char %d is: %c\n", count, arrChar[count]);
		count++;
		
	}

	return 0;
}
