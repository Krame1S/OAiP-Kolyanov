#pragma once
#include <stdio.h>
#include <time.h>

void output_wrong_input();
void output_sorted_array(int* SIZE, int** array);
void output_array(int* SIZE, int** array);
void output_sorted_array_worst_case(int SIZE, int** array);
void output_k_promt();
void output_no_elements_to_sort();
void output_unable_to_sort();
void output_fastest_sort(double bubble_sort_time, double selection_sort_time);