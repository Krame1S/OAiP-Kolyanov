#include "output.h"

void output_initial_array(int* rows, int* cols, int*** array)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 1; j <= *cols; j++)
		{
			printf("%d ", (*array)[i][j]);
		}
		printf("\n");
	}
}

void output_array(int* rows, int* cols, int*** array)
{
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 0; j <= *cols; j++)
		{
			printf("%3.d ", (*array)[i][j]);
			if (j == 0)
				printf("			");
		}
		printf("\n");
	}
}

void output_wrong_input()
{
	printf("Wrong input\n");
}

void task_output()
{
	printf("TASK\nIn an NxM matrix, sort the rows in ascending order of the sum of positive elements using the Shell sort\n\n\n");
}