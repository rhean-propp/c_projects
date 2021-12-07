#include<stdio.h>


int main (void) {

	printf("\nWelcome to the binary calculator. Enter a value above 65535 to quit.\n\n");

	//   | Declare Variables
	//---|-----------------------------------------
	// 1 | aval is input given by user
	//   | rem 1 - 16 store remainder values of modulous operator

	unsigned int aval;
	int rem1, rem2, rem3, rem4, rem5, rem6, rem7, rem8;
	int rem9, rem10, rem11, rem12, rem13, rem14, rem15, rem16;

	for (aval = 0; aval <= 65535;) {
		printf("Input your value: ");
		scanf("%d", &aval);
		
		// If user enters a value higher than 65535, program quits.
		
		if (aval > 65535)
			break;
		
		//   | Conversion Table
		//---|---------------------------------------
		// 1 | Take modulo of aval. Store it as rem#
		// 2 | Divide aval by 2
		// 3 | Repeat

		rem1 = aval%2;
		aval /= 2;
		
		rem2 = (aval%2);
		aval /= 2;
		
		rem3 = (aval%2);
		aval /= 2;
		
		rem4 = (aval%2);
		aval /= 2;
		
		rem5 = (aval%2);
		aval /= 2;
		
		rem6 = (aval%2);
		aval /= 2;
		
		rem7 = (aval%2);
		aval /= 2;
		
		rem8 = (aval%2);
		aval /= 2;
		
		rem9 = (aval%2);
		aval /= 2;
		
		rem10 = (aval%2);
		aval /= 2;
		
		rem11 = (aval%2);
		aval /= 2;
		
		rem12 = (aval%2);
		aval /= 2;
		
		rem13 = (aval%2);
		aval /= 2;
		
		rem14 = (aval%2);
		aval /= 2;
		
		rem15 = (aval%2);
		aval /= 2;
		
		rem16 = (aval%2);
		aval /= 2;
		
		//   | Print Program Output
		//---|-----------------------------------------
		// 1 | The most significant bit on the right
		// 2 | The true binary value of the user input
		
		printf("\n\nMost significant bit on the right:\n\n\n\t%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n\n\n", rem1, rem2, rem3, rem4, rem5, rem6, rem7, rem8, rem9, rem10, rem11, rem12, rem13, rem14, rem15, rem16);
		
		printf("Binary value:\n\n\n\t%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d\n\n\n", rem16, rem15, rem14, rem13, rem12, rem11, rem10, rem9, rem8, rem7, rem6, rem5, rem4, rem3, rem2, rem1);
	
	}

	return 0;
}