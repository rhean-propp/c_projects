#include<stdio.h>

int main (void) {

	char array[17] = "ABCDEFGhijklmnop";
	
	printf("array content: %s\n", array);
	
	array[8] = '\0';
	
	printf("array content: %s\n", array);


}
