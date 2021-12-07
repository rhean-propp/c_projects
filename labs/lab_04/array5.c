#include<stdio.h>


int main (void) {

	int val;
	char arr[10];
	char var;
	
	printf("address of val: %p\n", &val);
	printf("address of arr: %p\n", arr);
	printf("address of arr: %p\n", &arr[0]);
	printf("address of var: %p\n", &var);
	

	return 0;
}

