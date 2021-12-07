#include<stdio.h>


int main (void) {

	int index = 0;
	int size = 0;
	
	char arr2[] = {"ABCDEFGHIJKLMNOP"}; // a string is a continuous block of characters	
	
	for (int index = 0; index < sizeof(arr2)/sizeof(char)-1; index++) {
	
		printf("arr2[%d]: %c, arr2[%d] + 32 = %c\n", index, arr2[index], index, arr2[index] + 32);
	}

	return 0;
}

