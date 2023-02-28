#include "array.h"


void array_mem_alloc(int* SIZE, int** array)
{
	*array = (int*)malloc(sizeof(int) * (*SIZE));
}

void array_mem_realloc_for_worst_case(int *SIZE, int** array)
{
	*array = (int*)realloc(*array, sizeof(int) * (*SIZE));
}

void array_swap1(int** array1, int x, int y)
{
	int buf;
	buf = array1[x];
	array1[x] = array1[y];
	array1[y] = buf;
}