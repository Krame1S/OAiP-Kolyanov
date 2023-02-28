#include "task2.h"

int task2()
{
	char* stringS = (char*)calloc(1, 1);
	char* stringS0 = (char*)calloc(1, 1);
	char C;
	printf("\nThis program will insert string S0 before each occurrence of the character C in the string S\nEnter string S:\n");
	input_string(&stringS);
	printf("Enter character C:");
	input_C(&C);
	printf("Enter string S0:\n");
	input_string(&stringS0);
	printf("Here is your initial string:\n%s\n", stringS);
	string_insert(&stringS, &stringS0, C);
	printf("Here is your new string:\n%s\n", stringS);
	free(stringS);
	free(stringS0);
	printf("\nThat's the end of the program.\n");
	input_later_instructions();
}