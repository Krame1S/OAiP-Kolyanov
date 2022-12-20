#include "arrays.h"

void array_mem_alloc(int* rows, int* cols, int*** array)
{
    (*array) = (int**)malloc((*rows) * sizeof(int*));
    for (int i = 0; i < (*rows); i++)
    {
        (*array)[i] = (int*)malloc(((*cols) + 2) * sizeof(int));
    }
}

void array_swap(int*** array, int* cols, int ind1, int ind2)
{
    int temp;
    for (int i = 1; i <= *cols; i++)
    {
        temp = (*array)[ind1][i];
        (*array)[ind1][i] = (*array)[ind2][i];
        (*array)[ind2][i] = temp;
    }  
}

int array_row_sum_of_pos(int*** array, int row, int* cols)
{
    (*array)[row][0] = 0;
    for (int i = 0; i <= *cols; i++)
    {
            if ((*array)[row][i] > 0)
                (*array)[row][0] += (*array)[row][i];
    }
    return (*array)[row][0];
}