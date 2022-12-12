#include "arrays.h"

void array_allocate_memory(int* rows, int*** array)
{
    (*array) = (int**)malloc((*rows) * sizeof(int*));
    for (int i = 0; i < (*rows); i++)
    {
        (*array)[i] = (int*)malloc(2 * sizeof(int));
    }
}

void duplicate_elems_greater_then_k(int* k, int* rows, int*** array)
{
    int size=0;
    for (int i = 0; i < *rows; i++)
    {
        size = (*array)[i][0];
        for (int j = 1; j < size; j++)
        {   
            if ((*array)[i][j] > (*k))
            {
                int* temp = (int*)realloc((*array)[i], sizeof(int) * (size + 2));
                if (temp != NULL)
                    (*array)[i] = temp;
                for (int t = 0; t < (size - j); t++)
                {
                    (*array)[i][size - t] = (*array)[i][size - t - 1];
                }
                size++;
                j++;
            }
            (*array)[i][0] = size;
        }
    }



}

void array_free(int* rows, int*** array)
{
    for (int i = 0; i < *rows; i++)
    {
        free((*array)[i]);
    }
    free(*array);
}

