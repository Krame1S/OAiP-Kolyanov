#include "input.h"

void input_array_size(int* rows, int* cols)
{
	output_enter_rows_promt();
	while (scanf_s("%d", rows) == 0 || *rows <= 0 || *rows > 50 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	output_enter_cols_promt();
	while (scanf_s("%d", cols) == 0 || *cols <= 0 || *cols > 50 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_array(int* rows, int* cols, int*** array)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j < *cols; j++)
		{
			while (printf("elem[%d][%d] = ", i, j), scanf_s("%d", &(*array)[i][j]) == 0 || getchar() != '\n')
			{
				output_wrong_input();
				rewind(stdin);
			}
		}
	}
	
}