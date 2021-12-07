// DIvide a number by 3 and print the output repeatedly.

/* 

	1. Get input from user.
	2. Divide the number then store the new number.
	3. Print the result of division.	
	4. Check to see if we can divide the number again
	5. Repeat starting at step 2

*/

#include<stdio.h>


int main (void) {

	int user_input;
	
	printf("Give me a number: ");
	scanf("%d", &user_input);
	
	for (; user_input > 0; user_input /= 3) {
	
		printf("%d\n", user_input);
	
	}



	return 0;
}
