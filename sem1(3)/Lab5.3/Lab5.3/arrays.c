#include "arrays.h"

void array_mem_alloc(int* rows, int* cols, int*** array)
{
    (*array) = (int**)malloc( (*rows) * sizeof(int*) );
    for (int i = 0; i < (*rows); i++)
    {
        (*array)[i] = (int*)malloc( (*cols) * sizeof(int) );
    }
}

void array_find_saddle_point(int* rows, int* cols, int*** array)
{
    int max, ind_max = 0, ind_row = 0, count = 0, flag = 0, flag2 = 0;
    max = RAND_MAX * (-1);
    for (int i = 0; i < *rows; i++)
    {
        flag = 0;
        int checker = 1;
        for (int j = 0; j < *cols; j++)
        {
            if ((*array)[i][j] == max)
            {
                flag = 1;
                break;
            }
            else if ((*array)[i][j] > max)
            {
                max = (*array)[i][j];
                ind_max = j;
            }
        }
        for (int j = 0; j < *rows; j++)
        {
            if (flag == 1)
                break;
            if (((*array)[j][ind_max] == max && (i) != j) || (*array)[j][ind_max] < max)
            {
                break;
            }
            else
            {
                if (checker == *rows)
                {
                    flag2 = 1;
                    output_saddle_point(&i, &ind_max, array);
                    array_del_colon_with_saddle_point(&ind_max, rows, cols, array);
                }
                else
                    checker++;
            }
        }
    }
    if (flag2 == 0)
        output_no_sitting_point();
}

void array_del_colon_with_saddle_point(int* ind_max, int* rows, int* cols, int*** array)
{
    for (int k = 0; k < *rows; k++)
    {
        for (int p = (*ind_max); p < *cols; p++)
        {
            (*array)[k][p] = (*array)[k][p + 1];
        }
    }
    (*cols)--;
    for (int j = 0; j < *rows; j++)
    {
        (*array)[j] = (int*)realloc((*array)[j], sizeof(int) * (*cols));
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

void transp_matrix(int row, int col, int*** matrix)
{
    int buf = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            buf = (*matrix)[j][i];
            (*matrix)[j][i] = (*matrix)[i][j];
            (*matrix)[i][j] = buf;
        }
    buf = 0;
    buf = row;
    row = col;
    col = buf;
}