/*

4 bits of binary number

User enters 1111, we expect output of 15.

	1. Instructions
	2. Get Input
	3. Limit input to 4 digits
	4. Limit input to 1s and 0s (if !1 || !0)
	5. Convert individual bits from user input
	6. Add positional values

*/

#include<stdio.h>
#include<math.h>


int main (void) {

	int binary_input = 0;
	int ram = 0;
	int sum = 0;
	int decimal_multiplier = 1000;

	printf("Please enter a binary 4 bit number: ");
	scanf("%d", &binary_input);

	// divide by 1000
	// subtract 1000 by the number
	// divide the number by 100
	// subtract 100
	// divide by 10
	// subtract 10
	// divide by 1
	ram = binary_input;
	
	for (int loop_count = 3; loop_count > 0; loop_count--) {
	

		ram /= decimal_multiplier;		// Is the number 0 or 1?
		printf("ram = %d, decimal_multiplier = %d\n", ram, decimal_multiplier); 			// Debug

		if (ram == 1) {
			ram = pow(2, loop_count);
			// printf("%d\n", ram); 			// Debug
			sum = sum + ram;
			ram = binary_input;
		} 

		ram = (binary_input - decimal_multiplier);
		decimal_multiplier /= 10;
	}
	printf("%d", sum);
	
/*
	ram = binary_input;
	ram /= 1000;		// Is the number 0 or 1?
	printf("%d\n", ram); // Debug
	if (ram == 1) {
		ram = pow(2, loop_count);
	}
	printf("Ram^3 = %d\n", ram); // Debug
	sum += ram;
	binary_input -= 1000;
	
	ram = binary_input;
	ram /= 100;
	printf("%d\n", ram); // Debug
	*/

	return 0;
}
