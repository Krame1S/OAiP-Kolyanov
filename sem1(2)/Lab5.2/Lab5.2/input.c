#include "input.h"

void input_array_size(int* rows)
{
	while (scanf_s("%d", rows) == 0 || *rows <= 0 || *rows > 50 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	if (*rows != 1)
		output_null_enter_promt();
}

void input_array(int* rows, int*** array)
{
	for (int i = 0; i < *rows; i++)
	{
		int j = 1;
		for (;;)
		{
			if (printf("elem[%d][%d] = ", i, j-1), scanf_s("%d", &(*array)[i][j]) != 0 && (*array)[i][j] != 0)
			{
				 int *temp = (int*)realloc((*array)[i], sizeof(int) * (j + 2));
				 if (temp != NULL)
					 (*array)[i] = temp;
				j++;
			}
			else if((*array)[i][j] == 0)
			{
				printf("\n");
				(*array)[i][0] = j;
				j++;
				break;
			}
			else
			{
				output_wrong_input();
				rewind(stdin);
			}
		}
		
	}
}

void input_k(int* k)
{
	while(scanf_s("%d", k) == 0 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}