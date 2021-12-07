#include<stdio.h>


int main () {

	for (int row = 1; row <= 9; row++) {
	
		for (int col = 1; col <= 5; col++) {
			
			if ((row % 2 ) == 0) { 								// If row is even
				;
			} else if ((row == 3 || row == 7 ) && ((col % 2 ) == 1)) {			// If column is odd
				printf(" ");
			} else if (row == 5 && ((col % 2 ) == 0)) {					// If column is even
				printf(" ");
			} else {
				printf("*");
			}
			
		}
		
		printf("\n");
	}

	return 0;
}