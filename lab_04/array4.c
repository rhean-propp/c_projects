#include<stdio.h>


int main (void) {

	int index = 0;
	
	char arr[12];
	
	printf("Please enter a string: ");
	scanf(" %[^\n]s", arr);				// [^\n] dont stop until you see the newline character
	
	for (; index < 20; index++) {
	
		printf("arr[%d]: %c\n", index, arr[index]);
	}
	
	printf("\nYour string was: %s\n", arr);

	return 0;
}

