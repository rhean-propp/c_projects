#include<stdio.h>

int main (void) {
	
	int decimal = 0;		// [BINARY] Decimal input from user.
	int binary[17] = {0};		// [BINARY] Stores binary values
	int index = 0;			// [BINARY] Used for removing unecessary sets of 0000s before the binary number
	
	int sum = 0;			// [HEX] The sum of the binary number in decimal.
	int num = 16;			// [HEX] The representation of each binary value in a byte. (8, 4, 2, 1)
	int bitLength = 0;		// [HEX] Keeps track of bits cycled through
	
	// Get Decimal Input Section
	
	printf("\nPlease input a positive decimal number no greater than 65535.\n\nDecimal: "); 	// Instructions for user.
	scanf(" %d", &decimal);										// Get decimal input
	
	if (decimal > 65535) {									// If input too high:
		printf("\nYour input was too high.\nPlease run the program again.\n\n");	// Instructions
		return 0;									// Quit program
	}
	
	// Convert and store Decimal as Binary
	
	for(int count = 16; count > 0; count--) {	// Iterates 16 times. Loop is decremented to store values in correct locations.
		binary[count-1] = (decimal % 2);	// count-1 is used to prevent truncation. Code evaluates if 1 or 0, then stores.
		decimal /= 2;				// Divides by two. This moves the code to the next evaluation for 0 or 1.
		
	} 
	
	// Output Binary
	// This loop checks how many 0s are in the array before the first 1 appears.
	
	for (int count = 0; binary[count] == 0; count++) {	// Loops until the first 1 appears in the array.
		++index;					// Counts 0s
	}	
	
	// This conditional logic filters the index into a fixed number category
	
	if (index >= 4 && index <= 7 ) {		// If index is between 4 and 7 inclusive
		index = 4;				// Removes 1 set
	} else if (index >= 8 && index <= 11 ) {	// If index is between 8 and 11 inclusive
		index = 8;				// Removes 2 sets
	} else if (index >= 12 && index <= 15) {	// If indexi is between 12 and 15 inclusive
		index = 12;				// Removes 3 sets
	} else {					// If index is between 0 and 3 inclusive
		index = 0;				// Removes 0 sets
	}
	
	// This loop prints the binary value value from the array with applied filters.
	
	printf("Binary:\t");					// Formatting
	for (int count = index; count < 16; count++) {		// Loop starts at index category specified earlier
		if (count % 4 == 0)				// Prints spaces every 4 digits
			printf(" ");				// Prints space					
		printf("%d", binary[count]);			// Prints the binary value stored in the array.
			
	}
	
	// Convert Binary to Hex & Output
	
	printf("\nHex:\t 0x");
	
	for (int count = index; count < 16; count ++ ) {	// Loops through the binary array
		if (binary[count] == 1) {			// If the binary value is 1
			num = num/2;				// Decreases the place value by half
			sum += num;				// Stores the binary as a decimal summation
		} else if (binary[count] == 0 ) {		// If the binary value is 0
			num = num/2;				// Decreases the place value by half
		}  else {					// Else
			;					// Do nothing
		}
		
		if (bitLength == 3) {			// If the the full byte has been cycled through
			if (sum >= 10) {		// If the value is 10 or above
				sum += 55;		// Add 55 to represent the value as a character
				printf("%c", sum);	// Print the hexidecimal value from A - F
			} else {			// If bitLength is not 3
				printf("%d", sum);	// Print the hexidecmal value from 0 - 9.
			}
			
			// Reset for next byte
			num = 16;		// Reset the place value
			bitLength = -1;		// Reset the bit length counter
			sum = 0;		// Reset the sum
		}
		bitLength++;
	}
	
	printf("\n\n");

	return 0;
}