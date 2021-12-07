#include<stdio.h>


int main () {

	for (int row = 1; row <= 5; row++) {
	
		int col = 1;
	
		while (col <= 8) {
			
			if ((row == 2 || row == 4 ) && (col == 1 || col == 8)) {
				printf(" ");
			} else if (row == 3 && (col < 4 || col > 5)) {
				printf(" ");
			} else {
				printf("*");
			}
			
			col++;
			
		}
		
		printf("\n");
	}

	return 0;
}