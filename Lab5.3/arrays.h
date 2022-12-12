#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include <time.h>

void array_mem_alloc(int* rows, int* cols, int*** array);
void array_find_saddle_point(int* rows, int* cols, int*** array);
void array_del_colon_with_saddle_point(int* ind_max, int* rows, int* cols, int*** array);
void array_free(int* rows, int*** array);