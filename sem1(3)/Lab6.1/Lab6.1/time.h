#pragma once
#include <time.h>
#include <stdio.h>
#include "array.h"

void time_clocking_bubble_sort(int* k, int* SIZE, int** array, int* FLAG, double* bubble_sort_time);
void time_clocking_selection_sort(int* k, int* SIZE, int** array, double* selection_sort_time);
void time_clocking_worst_case_bubble_sort(int* k, int* SIZE, int** array, int* FLAG, double* bubble_sort_worst_case_time);
void time_clocking_worst_case_selection_sort(int* k, int* SIZE, int** array, double* selection_sort_worst_case_time);
