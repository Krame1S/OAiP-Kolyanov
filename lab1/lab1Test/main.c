#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main()
{
	PC* list = NULL;
	int amountOfPCs = 0;
	menu(&list, &amountOfPCs);
	free(list);
	return 0;
}
