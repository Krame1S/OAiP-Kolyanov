#include "sort.h"

void shell_sort(int*** array, int* rows, int* cols) 
    {
    int i, j, gap, a, b, count = 0;
    for (gap = (*rows) / 2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < *rows; i++) 
        {
            for (j = i - gap; j >= 0; j -= gap) 
            {
                a = array_row_sum_of_pos(array, j, cols);
                if ((*array)[j][0] == 0)
                    break;
                b = array_row_sum_of_pos(array, j + gap, cols);
                if ((*array)[j + gap][0] == 0)
                    break;
                if (a > b)
                {
                    array_swap(array, cols, j, j + gap);
                    count = 1;
                    if (count == 1)
                        break;
                }
            }
            if (count == 1)
                break;
        }
        if (count == 1)
            break;
    }
}