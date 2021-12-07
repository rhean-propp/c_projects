#include<stdio.h>

int main (void) {

	char arrchr[10] = "Hello";
	
	// How many bytes are being used for arrchr?
	// 6 Bytes for the string hello and for the null terminator
	
	printf("Before modifying array: %s\n", arrchr);
	
	printf("Enter a new string: ");
	scanf(" %s", arrchr);
	
	printf("After modifying array: %s\n", arrchr);
	
	

	return 0;
}
