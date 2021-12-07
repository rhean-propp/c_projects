#include<stdio.h>

int main()
{
	char choice;
	
	printf("Please enter a choice for title (a) or uppercase (b): ");
	scanf(" %c", &choice);

	if (choice == 'a') {
		printf ("You want title case\n");
		// Do the title case
	} else {
		printf("You want caps\n");
		// Do the caps case
	}
	
	char arr[20] = {"\0"}; // Initialize the first character and all others will be initialized to NULL terminator.
/*
	printf("Please enter a string: ");
	scanf(" %[^\n]s", arr); // The space " %" before the % sign, clears the buffer. The [^\n] allows %s to read the spaces inbetween words. \n should be used as the terminating sequence instead of the default which is space. (" ")
	
	printf("You entered the string: %s", arr);
	*/
	
	// char *fgets(char *s, int size, FILE *stream);
	fgets (arr, sizeof(arr), stdin);	// stdin is the standard input stream; think keyboard
	fgets (arr, sizeof(arr), stdin);
	printf("After second fgets: arr: %s", arr);
	
	/*
	for (int count = 0; count > 19; count++)
		printf("arr[%d]: %x\n", count, arr[count]);
	*/
	
	return 0;	
}
