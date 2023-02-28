#include "input.h"

void input_k(int* k)
{
	output_k_promt();
	while (scanf_s("%d", k) == 0 || *k == 0 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}

}

void input_array_size(int* SIZE)
{
	while (scanf_s("%d", SIZE) == 0 || *SIZE == 1 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_array(int* SIZE, int** array1)
{
	printf("Enter the elements of array:\n");
	for (int i = 0; i < *SIZE; i++)
	{
		while (scanf_s("%d", &(*array1)[i]) == 0 || getchar() != '\n')
		{
			output_wrong_input();
			rewind(stdin);
		}

	}
}

void random_input(int* SIZE, int** array1)
{
	int sign;
	srand(time(NULL));
	(*array1)[0] = 1000;
	printf("%d", (*array1)[0]);
	for (int i = 1; i < *SIZE; i++)
	{
		sign = rand();
		if (sign % 2 == 0)
		{
			(*array1)[i] = rand() % 200 - 100;
			(*array1)[i] *= (-1);
		}
		else
			(*array1)[i] = rand() % 200 - 100;
		printf("%d\n", (*array1)[i]);
	}
}

void input_choice(int* choice, int* SIZE, int** array1)
{
	while (scanf_s("%d", choice) == 0 || (*choice != 1 && *choice != 2) || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	switch (*choice)
	{
	case 1:
		random_input(SIZE, array1);
		break;
	case 2:
		input_array(SIZE, array1);
		break;
	}
}

void input_worst_case(int *SIZE, int** array)
{
	for(int i = 0; i < *SIZE; i++)
	{
		(*array)[i] = *SIZE - i;
	}
}