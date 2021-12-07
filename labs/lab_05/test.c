#include<stdio.h>


int main (void) {

	const int MAX_NUM = 10;

    char arr[MAX_NUM];
    
    int arrayLength = 0;
    int arraySize = 0;
    
    // Get input, convert to uppercase

    printf("Enter a string 10 characters or less: ");
    scanf(" %[^\n]s", arr);
    
    for (int counter = 0; counter < MAX_NUM; counter++) {
    
    	if ( arr[counter] >= 'a' && arr[counter] <= 'z') {
    		printf("%c", arr[counter] - 32);
    	} else {
    		printf("%c", arr[counter]);	
    	}
    
    }
    
    // Display length of array
    
    arraySize = sizeof(arr);
    printf("\nThe size of the array is: %d", arraySize);
    
    for (int count = 0; count < MAX_NUM && arr[count] != '\0'; count++) {
    
    	arrayLength += 1;

    }
    
    printf("\nThe length of the array is: %d\n", arrayLength);
   

    return 0;
}
