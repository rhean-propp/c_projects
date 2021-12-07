#include<stdio.h>


int main (void) {


	int row, col;
	
	for (row = 0; row <= 11; row++) {
	
		for (col = 0; col <= 11; col++) {
		
			if(((col >=2 && row >=2) && ( col <= row )) && ( row != 11)) {
				printf(" ");
			} else {
				printf("*");
			}
		
		}
		
		printf("\n");
	
	
	}



	return 0;
}
