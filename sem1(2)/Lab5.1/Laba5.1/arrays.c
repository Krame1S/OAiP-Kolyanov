#include "arrays.h"

void arrays_del_smaller_then_prew(int *SIZE, int **arr)
{
	for (int i = 0; i < (*SIZE)-1; i++)
	{
		if ((*arr)[i + 1] < (*arr)[i])
		{
			for (int j = i+1; j < (*SIZE)-1; j++)
			{
				(*arr)[j] = (*arr)[j + 1];
			}
			(*SIZE)--;
			i--;
			*arr = realloc(*arr, (*SIZE) * sizeof(int));
		}
	}
}