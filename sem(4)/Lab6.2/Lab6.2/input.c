#include "input.h"

void input_array_size(int* rows, int* cols)
{
	printf("Enter amount of rows:\n");
	while (scanf_s("%d", rows) == 0 ||*rows <= 0 || *rows > 50 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	printf("Enter amount of cols:\n");
	while (scanf_s("%d", cols) == 0 || *cols <= 0 || *cols > 50 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_array(int* rows, int* cols, int*** array)
{
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < *rows; i++)
	{
		for (int j = 1; j <= *cols; j++)
		{
			while (printf("elem[%d][%d] = ", i, j), scanf_s("%d", &(*array)[i][j]) == 0 || getchar() != '\n')
			{
				output_wrong_input();
				rewind(stdin);
			}
		}
	}
}

void random_arr_input(int* rows, int* cols, int*** array)
{
	int sign;
	srand(time(NULL));
	for (int i = 0; i < (*rows); i++)
	{
		for (int j = 1; j <= (*cols); j++)
		{
			sign = rand();
			if (sign % 2 == 0)
			{
				(*array)[i][j] = rand() %200 - 100;
				(*array)[i][j] *= (-1);
			}

			else
			{
				(*array)[i][j] = rand() %200 - 100;
			}

		}
	}
}

void input_choice(int* choice, int* rows, int* cols, int*** array)
{
	while (scanf_s("%d", choice) == 0 || (*choice != 1 && *choice != 2) || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	switch (*choice)
	{
	case 1:
		random_arr_input(rows, cols, array);
		break;
	case 2:
		input_array(rows, cols, array);
		break;
	}
}
