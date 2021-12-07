#include<stdio.h>

int main() {

	unsigned char var1 = 0x10; // This is 16
	unsigned char var2 = 0xFF; // This is 255
	
	// char is being treated as a signed value.
	
	printf("var1 & var2 %d\n", var1 & var2); // Bitwise AND
	printf("var1 | var2 %d\n", var1 | var2); // Bitwise OR
	printf("var1 ^ var2 %d\n", var1 ^ var2); // Bitwise XOR
	printf("~var2 %x\n", ~var2);			 // Bitwise NOT


	return 0;
}

