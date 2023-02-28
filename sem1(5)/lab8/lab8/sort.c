#include "sort.h"
#pragma warning(disable : 4996)

void insert_sort(char*** string, const int argc)
{
	for (int i = 2; i < argc; i++)
	{
		for (int j = i; j > 1 && strlen((*string)[j - 1]) < strlen((*string)[j]); j--)
		{
			char* temp = (char*)calloc(1, 255);
			strcpy(temp, (*string)[j]);
			strcpy((*string)[j], (*string)[j - 1]);
			strcpy((*string)[j - 1], temp);
			free(temp);
		}
	}
}