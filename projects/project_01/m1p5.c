#include<stdio.h>

int main (void) {

	int x = 2;
	float y = 25.8;
	
	printf("Float: %f, Integer: %d\n", y, x);
		
	y = (int) y;		
		
	printf("Float: %f, Integer: %d\n", y, x);

	return 0;
}