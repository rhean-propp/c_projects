#include<stdio.h>


int main () {

	int ram, sum, counter;
	float average;
	
	sum = 0;

	for (counter = 0; counter < 10; ++counter) {
	
		printf("Please enter number %d: ", counter+1);
		scanf("%d", &ram); 
		
		sum += ram;
	
	}
	
	average = (float)sum/(float)counter;
	
	printf("\nAverage: %.2f\nSum: %d\n", average, sum);
	
	if (sum%2 == 1) {
		printf("\nThe sum is odd.\n\n");	
	} else {
		printf("\nThe sum is even.\n\n");
		}

	return 0;
}