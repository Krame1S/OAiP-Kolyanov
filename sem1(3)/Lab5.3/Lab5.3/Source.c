#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"

int main()
{
	int** matrix = NULL;
	int row = 0; int col = 0;
	array_mem_alloc(row, col, &matrix);
	printf("inpur row and col\n");
	input_array_size(&row, &col);
	printf("inpur matrix:\n");
	input_array(row, col, &matrix);
	transp_matrix(row, col, &matrix);
	output_enter_array_promt();
	return 0;
}