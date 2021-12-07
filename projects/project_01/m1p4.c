#include<stdio.h>

int main() {

	unsigned short int aval = 65535;					// Max value of unsigned short is assigned.
	unsigned short int bval = 0;			
	int cval;								// Value is set to 0 on declaration.

	printf("First printf statment:\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);
	bval = aval + 1;							// Cannot be 65535. Therefore becomes 0.
	cval = aval + 1;							// Increases value by 1.
	printf("Second printf statment:\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);

	return(0);
}