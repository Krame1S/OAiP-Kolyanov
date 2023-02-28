#include "output.h"

void output_string(char** string, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		printf("%s\n", string[i]);
	}
}