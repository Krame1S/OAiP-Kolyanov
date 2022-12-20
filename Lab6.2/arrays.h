#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"
#include "output.h"
#include "sort.h"

void array_mem_alloc(int* rows, int* cols, int*** array);
void array_swap(int** row1, int** row2);
int array_row_sum_of_pos(int*** array, int row, int* cols);