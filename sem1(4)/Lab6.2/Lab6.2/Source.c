#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"
#include "output.h"
#include "sort.h"


int main()
{
	task_output();
	int rows, cols, choice;
	input_array_size(&rows, &cols);
	int** array = NULL;
	array_mem_alloc(&rows, &cols, &array);
	printf("Enter 1 for random initialisation\nEnter 2 for manual initialisation:\n");
	input_choice(&choice, &rows, &cols, &array);
	printf("This is your initial array:\n");
	output_initial_array(&rows, &cols, &array);
	shell_sort(&array, &rows, &cols);
	printf("\nThis is the sorted array:\n");
	printf("Sum of positives:		The sorted array:\n");
	output_array(&rows, &cols, &array);

	return 0;
}