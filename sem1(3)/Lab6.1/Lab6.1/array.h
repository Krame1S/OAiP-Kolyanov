#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_mem_alloc(int* SIZE, int** array);
void array_swap1(int** array1, int x, int y);
void array_mem_realloc_for_worst_case(int *SIZE, int** array);