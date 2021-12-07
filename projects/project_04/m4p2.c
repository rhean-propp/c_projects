#include"m4p2.h"        // Prototypes, definitions and libraries reside in this custom header file

int main(void) {        // Begin program

    
    char reverseCheck[STRINGS][SIZE] = {'\0'};      // Array to store reversed string.
    int length[STRINGS] = {'0'};                    // Array keeps track of the length of each string
    char string[STRINGS][SIZE] = {'\0'};            // STRINGS = ROWs | SIZE = COLs | Set the size of the string array to 20. Default all characters to NULL.

    getStrings(string, reverseCheck, length);       // Get user input

    return 0;
}

void getStrings(char string[STRINGS][SIZE], char reverseCheck[STRINGS][SIZE], int length[STRINGS]) {

    printf("Enter %d strings with a max of %d characters.\n", STRINGS, SIZE-1);       // Instructions | SIZE-1 to leave an element for NULL.

    for(int count = 0; count < STRINGS; count++) {      // Iterate for the amount of input we want

        printf("String %d: ", count+1);      // Instructions | Display String Iteration
        scanf(" %[^\n]s", string[count]);    // Get user input, store it row by row

    }

    printf("\n");             // Formatting

    isPalindrome(string, reverseCheck, length);

}

void isPalindrome(char string[STRINGS][SIZE], char reverseCheck[STRINGS][SIZE], int length[STRINGS]) { // Compare to see if the user input is a pallindrome
    
    int auth = 0;       // Increases as long as the character at string is the same as reverseCheck

    reverseStr(string, reverseCheck, length);       // Reverse the string, bring the output back to isPalindrome

        for (int count = 0; count < STRINGS; count++) {              // Iterate STRINGS times

            for (int index = 0; index < length[count]; index++) {    // Iterate the length of the string

                if (string[count][index] != reverseCheck[count][index]) {   // If the user input string IS NOT equal to the reversed string
                    auth = 1;                                               // Set auth to 1 to mark it as NOT a palindrome
                } 
                
            }

            if (auth == 1) {                                                                   // If auth is equal to one. (A comparison was false.)
                printf("String %d: \"%s\" is not a palindrome.\n", count+1, string[count]);    // Print Not a palindrome                                                        // Leave the loop
            } else {                                                                           // If auth is equal to zero. (All comparisons were true.)
                printf("String %d: \"%s\" is a palindrome.\n", count+1, string[count]);        // Print String is a palindrome
            }
            
            auth = 0;       // Resets auth for the next string          

        }

}

void reverseStr(char string[STRINGS][SIZE], char reverseCheck[STRINGS][SIZE], int length[STRINGS]) {

    int size = 0;                                   // Temporarily stores string length
    int opposite = 0;                               // Used for the reverse string. While index decreases, opposite increases.
    
   // Get String Length
    for(int count = 0; count < STRINGS; count++) {      // Iterates through ROWs (STRINGS)

        for(int index = 0; index < SIZE; index++) {     // Iterates through COLs (SIZE)
                
            if (string[count][index] != '\0') {         // If the string character is not NULL
                    length[count] = ++size;             // Incriment string length and store the value in the array.
            }
        }
        size = 0;
    }

    // Reverse String
    for(int count = 0; count < STRINGS; count++) {                       // Iterates through ROWs (STRINGS)

        for(int index = length[count]; index >= 0; index--) {            // Iterates through COLs (SIZE)

            reverseCheck[count][opposite-1] = string[count][index];      // Reverse the string
            opposite++;
        }
        opposite = 0;                                                    // Reset to zero after counting a row.
    }

}