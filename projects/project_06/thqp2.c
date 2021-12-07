#include<stdio.h>
#include<string.h>
#include<ctype.h>       // For toupper and tolower functions.
#include<stdlib.h>      // For exit(-1) function


void swap(char *left, char *right) {                // Compares two strings. Swaps the letter if left string is higher than right string.

    while (*left != '\0' || *right != '\0') {       // As long as both strings are not NULL, execute loop.

        if(*left > *right) {                        // If the Left string letter is bigger than the right string letter.
            char temp = *left;                          // Store the left string letter in a temporary variable.
            *left = *right;                             // Make the left string letter equal to the right string letter.
            *right = temp;                              // Make the right string letter equal to the temporary value (the left string letter)
        }

        *(left++);                                  // Incriment variable for loop
        *(right++);                                 // Increment variable for loop
    }
}

void reverse(char *string) {
	
    int len_str = 0;
	int count = 0;

	while( *(string + count) )
	{
		count++;
	}

	for(int col = 0; col < count/2; col++)
	{
		char temp = *(string+col);
		*(string+col) = *(string+(count - col - 1));
		*(string+(count - col - 1)) = temp;
	}	
}

void title_rev(char *string) {
    
    int wordLength = 0;
    
    reverse(string);                                            // Reverses string 
    
    for(int count = 0; count < strlen(string); count++) {       // Loops through each element of the string
        string[count] = tolower(string[count]);                 // Lower cases each element one-by-one   

        if (wordLength == 0) {                                  // If the loop count is at the beginning of a new word.
            string[count] = toupper(string[count]);                 // Capitalize the element
            wordLength++;                                           // Increase the word count to indicate the loop count is not at the first letter of a word.
        } else if (string[count] == ' ') {                      // If the loop count encounters a space in the string
            wordLength = 0;                                         // Reset the word length to 0 to indicate the start of a new word.
        } else {                                                // If not the first letter of a new word or not a space.
            wordLength++;                                           // Print the letter normally.
        }
    }
    

}

void clr_input(char *string1) {
	
    char *pos = strchr(string1, '\n');
	if(pos)
	{
		*pos = '\0';
	}
	else
	{
		scanf("%*[^\n]");
		scanf("%*c");
	}
}

void getInput(char *string1, char *string2) {       // [Add] Added char *string2 to prototyped function.

	printf("\nPlease enter string 1: ");            // [Mod] "Please Enter a String: " to "Please enter string 1: "
	fgets(string1, 40, stdin);                      // [Oridingal] Unchanged

    printf("Please enter string 2: ");              // [Add] Duplicate the previous prompt.
    fgets(string2, 40, stdin);                      // [Add] Duuplicate the previous input.

	clr_input(string1);                             // [Original] Unchanged
    clr_input(string2);                             // [Add] Duplicated the line above.
}

void printStrings(char *string1, char *string2) {                       // Prints strings at their current state.
    printf("\n\tString 1: %s\n\tString 2: %s\n", string1, string2);     // Print string 1 & string 2.
}

void menu(char *string1, char *string2) {                                                                       // Prompts user with a menu select.

    char select = 'x';                                                                                          // Variable for storing user input. Default Initialization

    printf("\nChoose an option. Enter a letter:\n\t(a) swap\n\t(b) reverse\n\t(c) title reverse\nInput: ");     // Prompt User
    scanf(" %c", &select);                                                                                      // Get Input

    if (select == 'a') {                                                                                        // If (a)
        swap(string1, string2);                                                                                     // Swap strings
        printf("\nSwap Output:");                                                                                   // Formatting
    } else if (select == 'b') {                                                                                 // If (b)
        reverse(string1);                                                                                           // Reverse string 1
        reverse(string2);                                                                                           // Reverse string 2
        printf("\nReverse Output:");                                                                                // Formatting
    } else if (select == 'c') {                                                                                 // If (c)
        title_rev(string1);                                                                                         // Reverse and title case string 1
        title_rev(string2);                                                                                         // Reverse and title case string 2
        printf("\nTitle Reverse Output:");                                                                          // Formatting
    } else {                                                                                                    // If (invalid)
        printf("Invalid input. Restart program.\n");                                                                // Inform user.
        exit(-1);                                                                                                   // Exit program.
    }
}                    

int main() {
    
	char array1[40] = {'\0'};           // String 1 variable. Initalize arrays with NULL so there is no garbage when manipulated.
	char array2[40] = {'\0'};           // String 2 variable.
	
	getInput(array1, array2);           // Get two input strings from user.
    menu(array1, array2);               // Send the input to the menu system for the user to select how to manipulate the strings
    printStrings(array1, array2);       // Print the output

	return 0;
}