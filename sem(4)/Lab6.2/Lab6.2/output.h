#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "input.h"
#include "output.h"
#include "sort.h"

void output_initial_array(int* rows, int* cols, int*** array);
void output_array(int* rows, int* cols, int*** array);
void output_wrong_input();
void task_output();