#include<stdio.h>

int main () {

	printf("\n");
	
	for (int counter = 1; counter <= 13; counter++) {

			if ((counter % 2 ) == 1) {
				printf("*");
			} else if (counter == 2 || counter == 4 || counter == 6) {
				printf("?");
			} else {
				printf(">");
			}
			
		}

	printf("\n\n");

	return 0;
}
