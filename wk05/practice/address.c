#include<stdio.h>

int main() {
	char arr1[10];
	int arr2[10];

	for(int index = 0; index < 10; index++)
		printf("addresses > &arr1[%d]: %p. &arr2[%d]: %p\n", index, &arr1[index], index, &arr2[index]);

	return 0;
}
