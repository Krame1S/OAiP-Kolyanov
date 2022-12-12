#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"

int main()
{
	int rows, cols;
	input_array_size(&rows, &cols);
	int** array = NULL;
	array_mem_alloc(&rows, &cols, &array);
	output_enter_array_promt();
	input_array(&rows, &cols, &array);
	output_initial_array(&rows, &cols, &array);
	array_find_saddle_point(&rows, &cols, &array);
	output_new_array(&rows, &cols, &array);
	array_free(&rows, &array);
	return 0;
}