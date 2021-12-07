/*
Pattern 1
*
  * 
    * 
      *
        *
Pattern 2
    *
   *
  *
 *
*
Pattern 3

*/






#include<stdio.h>
 

int main()
{
    int col = 0;
    int row = 0;
    int numrows = 0;
    
    printf("Enter rows: ");
    scanf("%d", &numrows);
    
    for(row = 0; row < numrows; row++) {
        for(col = 0; col < numrows; col++) {
			
 			if (row == col ) {
 				printf("*");
 			} else {
 				printf(" ");
 			}
			
        }
        printf("\n");
    }
    
    printf("\nPattern 2:\n\n");
    
    for(row = 0; row < numrows; row++) {
        for(col = 0; col <= numrows; col++) {
			
 			if ((row + col) == numrows -1) {
 				printf("*");
 			} else {
 				printf(" ");
 			}
			
        }
        printf("\n");
    }
    
    
    printf("\nPattern 3:\n\n");
    
    for(row = 0; row < numrows; row++) {
        for(col = 0; col < numrows; col++) {
        
        	if ((row == numrows -1) || (col == numrows -1)) {
        		printf("*");
        	}else if((row + col) == numrows -1) {
 				printf("*");
 			} else {
 				printf(" ");
 			}
			
        }
        printf("\n");
    }
    
    return 0;
}
