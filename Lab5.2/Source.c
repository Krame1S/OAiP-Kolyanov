#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"
#include "output.h"

int main()
{
	int rows;
	printf("Enter the number of rows(it can be between 1 and 50): ");
	input_array_size(&rows);
	int** array = NULL;
	array_allocate_memory(&rows, &array);
	output_enter_array_promt();
	input_array(&rows, &array);
	printf("Enter k:\n");
	int k = 0;
	input_k(&k);
	output_initial_array(&rows, &array);
	duplicate_elems_greater_then_k(&k, &rows, &array);
	output_new_array(&rows, &array);
	array_free(&rows, &array);
	return 0;
}