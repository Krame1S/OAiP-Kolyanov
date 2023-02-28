#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"output.h"	

void array_allocate_memory(int* rows, int*** array);
void array_free(int* row, int*** array);
void duplicate_elems_greater_then_k(int* k, int* rows, int*** array);
void array_free(int* rows, int*** array);