#include "output.h"

void output_enter_rows_promt()
{
	printf("Enter the amount of rows:\n");
}

void output_enter_cols_promt()
{
	printf("Enter the amount of cols:\n");
}

void output_wrong_input()
{
    printf("Wrong input. Try again:\n");
}

void output_enter_array_promt()
{
    printf("Enter the elements of the array:\n");
}

void output_null_enter_promt()
{
	printf("Type 0 to start entering the next row:\n");
}

void output_one_enter_promt()
{
	printf(":\n");
}

void output_initial_array(int* rows, int*** array)
{
	printf("\nHere is your initial array:\n");
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 1; j < (*array)[i][0]; j++)
		{
			printf("%d ", (*array)[i][j]);
		}
		printf("\n");
	}
}


void output_new_array(int* rows, int*** array)
{
	printf("\nHere is your new array:\n");
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 1; j < (*array)[i][0]; j++)
		{
			printf("%d ", (*array)[i][j]);
		}
		printf("\n");
	}
}

void output_saddle_point(int* i, int* ind_max, int*** array)
{
	printf("This is the sitting point: array[%d][%d] = %d", *i, *ind_max, (*array)[*i][*ind_max]);
}

void output_no_sitting_point()
{
	printf("This is no sitting point in this array");
}