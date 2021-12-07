#include<stdio.h>

// Learn: sizeof operator, %p, printing memory address of a variable
// Print content of each variable


int main (void) {

	// Variables to Print

	short int aval = 100;
	int bval = 100;
	float cval = 100;
	double dval = 100;
	char eval = 100;
	unsigned char fval = 100;
	
	// Print Variable Name, Value of Variable, & of Variable, and Content of Variable (in bytes)
	
	printf("\nVariable Name:\t\taval\nValue of aval:\t\t%d\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", aval, &aval, sizeof(aval)); // aval
	printf("\nVariable Name:\t\tbval\nValue of bval:\t\t%d\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", bval, &bval, sizeof(bval)); // bval
	printf("\nVariable Name:\t\tcval\nValue of cval:\t\t%f\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", cval, &cval, sizeof(cval)); // cval
	printf("\nVariable Name:\t\tdval\nValue of dval:\t\t%lf\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", dval, &dval, sizeof(dval)); // dval
	printf("\nVariable Name:\t\teval\nValue of eval:\t\t%c\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", eval, &eval, sizeof(eval)); // eval
	printf("\nVariable Name:\t\tfval\nValue of fval:\t\t%d\n& of Variable:\t\t%p\nContent of Variable:\t%zu bytes\n\n", fval, &fval, sizeof(fval)); // fval

	return 0;
}