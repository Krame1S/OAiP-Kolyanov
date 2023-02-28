#include "time.h"

void time_clocking_bubble_sort(int* k, int* SIZE, int* array, int* FLAG, double* bubble_sort_time)
{
	clock_t start_bubble_sort = clock(); //starting clock
	bubble_sort(k, SIZE, array, FLAG); //sorting
	clock_t end_bubble_sort = clock(); //stoping clock
	*bubble_sort_time = (double)(end_bubble_sort - start_bubble_sort) / CLOCKS_PER_SEC; //transitioning to seconds
}

void time_clocking_selection_sort(int* k, int* SIZE, int* array, double* selection_sort_time)
{
	clock_t start_selection_sort = clock(); //starting clock
	selection_sort(k, SIZE, array); //sorting
	clock_t end_selection_sort = clock(); //stoping clock
	*selection_sort_time = (double)(end_selection_sort - start_selection_sort) / CLOCKS_PER_SEC; //transitioning to seconds
}

void time_clocking_worst_case_bubble_sort(int* k, int* SIZE, int* array, int* FLAG, double* bubble_sort_worst_case_time)
{
	clock_t start_bubble_sort = clock(); //starting clock
	bubble_sort(k, SIZE, array, FLAG); //sorting
	clock_t end_bubble_sort = clock(); //stoping clock
	(*bubble_sort_worst_case_time) = (double)(end_bubble_sort - start_bubble_sort) / CLOCKS_PER_SEC; //transitioning to seconds
}

void time_clocking_worst_case_selection_sort(int* k, int* SIZE, int* array, double* selection_sort_worst_case_time)
{
	clock_t start_selection_sort = clock(); //starting clock
	selection_sort(k, SIZE, array); //sorting
	clock_t end_selection_sort = clock(); //stoping clock
	(*selection_sort_worst_case_time) = (double)(end_selection_sort - start_selection_sort) / CLOCKS_PER_SEC; //transitioning to seconds
}