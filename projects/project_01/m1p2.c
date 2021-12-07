#include<stdio.h>

int main() {

	int userInput;

	printf("\n1. Reconnaissance\n2. Weaponization\n3. Delivery\n4. Installation\n5. Exploitation\n6. Privilege Escalation\n7. Command and Control\n8. Quit\n\nEnter the number associated with your choice: ");
	
	scanf("%d", &userInput);
	
	printf("\nYou entered the number: %d\n\nThanks for accessing this program. Quitting now.\n\n", userInput);

	return 0;
}