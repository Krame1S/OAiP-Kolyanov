#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"
#include "output.h"
#include "sort.h"

void input_array_size(int* rows, int* cols);
void input_array(int* rows, int* cols, int*** array);
void random_arr_input(int*** array, int* rows, int* cols);
void input_choice(int* choice, int* rows, int* cols, int*** array);