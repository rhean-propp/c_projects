#include<stdio.h>
#include<string.h>


void swap(char *left, char *right)
{
	if(*left > *right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
	}
}

void reverse(char *string)
{
	int len_str = 0;
	int count = 0;

	while( *(string + count) )
	{
		count++;
	}

	for(int col = 0; col < count/2; col++)
	{
		char temp = *(string+col);
		*(string+col) = *(string+(count - col - 1));
		*(string+(count - col - 1)) = temp;
	}	
}
/*******************************************************************
 * title_rev: is a function that takes the address of a string
 *            it reverses the string and then converts the string to
 *            title cased:
 * Example: This is my string become Gnirts Ym Si Siht
 *******************************************************************/
void title_rev(char *string)
{

}
/***********************************************************************************************
 * clr_stdin implemented based on code
 * Reference: https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c
 *
 ***********************************************************************************************/
void clr_input(char *string1)
{
	char *pos = strchr(string1, '\n');
	if(pos)
	{
		*pos = '\0';
	}
	else
	{
		scanf("%*[^\n]");
		scanf("%*c");
	}
}

void getInput(char *string1)
{
	printf("Please enter a string: ");
	fgets(string1, 40, stdin);
	clr_input(string1);
}
int main()
{
	char array1[40];
	char array2[40];
	
	getInput(array1);
	reverse(array1);



	return 0;
}