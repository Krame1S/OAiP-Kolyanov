#include "string.h"

int str_len(char** string)
{
	int len = 0;
	for (int i = 0; (*string)[i] != '\0'; i++)
		len++;
	return len;
}
