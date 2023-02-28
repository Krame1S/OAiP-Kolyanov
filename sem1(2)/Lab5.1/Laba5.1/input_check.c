#include "input_check.h"

void input_check_size(int *SIZE)
{
    while (scanf_s("%d", SIZE) == 0 || (*SIZE) < 0 || (*SIZE) > 100 || getchar() != '\n')
    {
        output_wrong_input();
        rewind(stdin);
    }
}

void input_check_arr(int *SIZE, int *arr)
{
	for (int i = 0; i < (*SIZE); i++)
	{
		while (scanf_s("%d", &arr[i]) == 0 || arr[i] >= 100 || arr[i] <= -100 || getchar() != '\n')
		{
			output_wrong_input();
			rewind(stdin);
		}
	}
}