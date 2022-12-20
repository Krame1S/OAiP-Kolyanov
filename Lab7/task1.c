#include "task1.h"

int task1()
{
	char* string = (char*)calloc(1, 1);
	int k = 0;
	printf("\nThis program will delete the Kth word in your sentence\nEnter your sentence here:\n");
	input_string(&string);
	printf("Enter k:\n");
	input_k(&k);
	string_del_word(&string, k);
	free(string);
	printf("\n\nThat's the end of the program.\n");
	input_later_instructions();
}