#include "sort.h"

void bubble_sort(int* k, int* SIZE, int* array, int* FLAG)
{
	int max, pos, flag = 0, ind, counter;
	max = array[0];
	for (int i = 0; i < *SIZE; i++)
	{
		if (max <= array[i])
		{
			max = array[i];
			ind = i;
		}
	}
	if (ind + 1 == *SIZE)
	{
		output_no_elements_to_sort();
		*FLAG = 1;
		return 0;
	}
	else if (ind + 2 == *SIZE)
	{
		output_unable_to_sort();
		*FLAG = 1;
		return 0;
	}
	else
	{
		do
		{

			counter = 0;
			for (int i = (ind + 1); i < *SIZE; i++)
			{
				if (array[i] % *k == 0 && flag == 0)
				{
					pos = i;
					flag = 1;
				}
				if (array[i] % *k == 0 && array[i] < array[pos] && pos < i)
				{
					int buf;
					buf = array[pos];
					array[pos] = array[i];
					array[i] = buf;
					pos = i;
					counter++;
				}
				else if (array[i] % *k == 0)
					pos = i;
			}
			flag = 0;
		} while (counter != 0);
	}
}

void selection_sort(int* k, int* SIZE, int* array)
{
	int max, ind_max, ind_min, min = 0, *storage, j = 0;
	max = array[0];
	storage = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < *SIZE; i++)
		if (max <= array[i])
		{
			max = array[i];
			ind_max = i;
		}
		int m = 0;
		for (int i = ind_max + 1; i < *SIZE; i++)
			if (array[i] % *k == 0)
			{
				storage[m] = i;
				storage = (int*)realloc(storage, sizeof(int) * (m + 2));
				m++;
			}
		min = array[storage[0]];
		for (int i = 0; i < m; i++)
		{
			min = RAND_MAX;
			for (j; j < m; j++)
				if (min > array[storage[j]])
				{
					min = array[storage[j]];
					ind_min = j;
				}
			j = i + 1;
			int buf;
			buf = array[storage[i]];
			array[storage[i]] = array[storage[ind_min]];
			array[storage[ind_min]] = buf;
		}
		free(storage);
}

