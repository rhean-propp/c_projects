#include<stdio.h>

int main (void) {

	char array1[10];
	int count = 0;

	
	while (count != 9) {
	
		printf("Please enter a character: ");
		scanf(" %c", &array1[count]);
		
		array1[count] = array1[count] - 32;
		count++;
		
	}
	
		array1[9] = '\0';
		printf("You entered: %s\n:", array1);
		
	return 0;
}
