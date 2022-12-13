#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "array.h"
#include "input.h"
#include "output.h"
#include "sort.h"


int main()
{
	int *array1, *array2, SIZE, k, FLAG = 0, choice;
	double bubble_sort_time, selection_sort_time, bubble_sort_worst_case_time, selection_sort_worst_case_time;
	printf("Enter array size: \n");
	input_array_size(&SIZE);
	array_mem_alloc(&SIZE, &array1);
	array_mem_alloc(&SIZE, &array2);
	printf("Enter 1 for random initialisation\nEnter 2 for manual initialisation:\n");
	input_choice(&choice, &SIZE, &array1, &array2); //user choosing the way he wants his array to be initialized: randomly or manualy
	output_array(&SIZE, &array1);
	input_k(&k); 

	time_clocking_bubble_sort(&k, &SIZE, &array1, &FLAG, &selection_sort_time);
	if (FLAG == 1) //checking if array can be sorted
		return 0;
	time_clocking_selection_sort(&k, &SIZE, &array2, &bubble_sort_time);
	printf("Here is the sorted array:\n");
	output_sorted_array(&SIZE, &array1);
	printf("Bubble sort time: %.10lfs\n", bubble_sort_time); 
	printf("Selection sort time: %.10lfs\n", selection_sort_time);
	output_fastest_sort(bubble_sort_time, selection_sort_time); //outputing the difference between one sort and the other
	
	//worst case scenario..
	SIZE = 1000;
	array_mem_realloc_for_worst_case(&SIZE, &array1);
	array_mem_realloc_for_worst_case(&SIZE, &array2);
	input_worst_case(&SIZE, &array1);
	input_worst_case(&SIZE, &array2);
	time_clocking_worst_case_bubble_sort(&k, &SIZE, &array1, &FLAG, &bubble_sort_worst_case_time);
	time_clocking_worst_case_selection_sort(&k, &SIZE, &array2, &selection_sort_worst_case_time);
	output_sorted_array_worst_case(SIZE, &array1);
	printf("\n\nWorst case bubble sort time: %.5lfs\n", bubble_sort_worst_case_time);
	printf("Worst case selection sort time: %.5lfs\n", selection_sort_worst_case_time);
	output_fastest_sort(bubble_sort_worst_case_time, selection_sort_worst_case_time);
	return 0;
}

