#include "output.h"

void output_wrong_input()
{
	printf("Wrong input\n");
}

void output_array(int* SIZE, int** array)
{
	printf("Here is your array:\n");
	for (int i = 0; i < *SIZE; i++)
	{
		printf("%d ", (*array)[i]);
	}
	printf("\n");
}


void output_sorted_array(int* SIZE, int** array)
{
	for (int i = 0; i < *SIZE; i++)
	{
		printf("%d ", (*array)[i]);
	}
	printf("\n");
}

void output_sorted_array_worst_case(int *SIZE, int** array)
{
	printf("\nHere is worst case sort:\n");
	for (int i = 0; i < *SIZE; i++)
	{
		printf("%d ", (*array)[i]);
	}
	printf("\n");
}

void output_k_promt()
{
	printf("\nEnter k: \n");
}
void output_no_elements_to_sort()
{
	printf("This array can not be sorted. Last element is the greatest, means: there are no elements to sort after it\n");
}

void output_unable_to_sort()
{
	printf("This array can not be sorted. There is only one element to sort..\n");
}

void output_fastest_sort(double bubble_sort_time, double selection_sort_time)
{
	if (bubble_sort_time > selection_sort_time)
		printf("Selection sort was faster by %.10lfs", bubble_sort_time - selection_sort_time);
	else
		printf("Bubble sort was faster by %.10lfs", selection_sort_time - bubble_sort_time);
}