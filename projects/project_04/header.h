#ifndef M2P4_H
#define M2P4_H

#include<stdio.h>

#define STRINGS 3
#define SIZE 21

void getStrings(char array1[STRINGS][SIZE], char array2[STRINGS][SIZE], int array3[STRINGS]);         // Gets user input, stores input in a 2D array
void isPalindrome(char array1[STRINGS][SIZE], char array2[STRINGS][SIZE], int array3[STRINGS]);       // Checks if string is palindrome.
void reverseStr(char array1[STRINGS][SIZE], char array2[STRINGS][SIZE], int array3[STRINGS]);         // Reverses string

#endif