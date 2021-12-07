#include<stdio.h>

int functionA();
int functionB();

void main () {

	for(int i = 0; i < 5; i++)
		printf("[FUNA] The value now is: %d\n", functionA());
		
	printf("\n");

	for(int i = 0; i < 5; i++)
		printf("[FUNB] The value now is: %d\n", functionB());
}

int functionA() {
	int valueA = 100;
	valueA +=1;
	return valueA;
}

int functionB() {
	static int valueB = 100;
	valueB +=1;
	return valueB;
}