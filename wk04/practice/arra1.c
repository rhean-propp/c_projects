#include<stdio.h>


int main (void) {

	int index = 0;
	int size = 0;
	
	char arr2[] = {"ABCDEFGHIJKLMNOP"}; // a string is a continuous block of characters	
							   // arr2 will get its size set by the compiler
							   // 8 characters, each 1 byte will be allocated for this array
							   // -----> you can't add to the array after this
	char arr3[30];		   
					
	while(arr2[index] != '\0') {
	
		printf("\tarr2[%d]: %c 0x%X\n", index, arr2[index], arr2[index]);
	
		index++;
	}						   
							   
	printf("Wow!\n");
	
	size = sizeof(arr2);
	printf("size of arr2 = %d\n", size);
	
	// THe size of does not count the number of elements. It counts the number of bytes
	// You need to know the number of elements before creating the array
	
	size = sizeof(arr3);
	printf("size of arr3 = %d\n", size);

	return 0;
}
