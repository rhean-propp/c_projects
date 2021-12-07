#include<stdio.h>

int main(void) {
	
	for (int row = 1; row <= 5; row++) {
	
		for (int col = 1; col <= row; col++) {
		
			if (row == col)	{
				
				printf("*");	
				
			} else {
			
				printf(" ");
				
			}
				
		}
		
		printf("\n");
	
	}	
	
	for (int row = 1; row <= 5; row++) {
	
		for (int col = 1; col <= 5; col++) {
		
			if ((row+col) == 6)	{
				
				printf("*");	
				
			} else {
			
				printf(" ");
				
			}
				
		}
		
		printf("\n");
	
	}	
	
	
	
	return 0;
}

