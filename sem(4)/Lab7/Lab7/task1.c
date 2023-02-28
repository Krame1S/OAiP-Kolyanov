#include "task1.h"

//transponirovatb matritsu
void array_allocate_memory(int rows, int cols, int*** array);
void input_size(int* row, int* col);
void input_array(int row, int col, int*** array);
void transp_matrix(int row, int col, int*** matrix);

int task1()
{
    int** matrix = NULL;
    int row = 0; int col = 0;
    array_allocate_memory(&row, &col, &matrix);
    printf("inpur row and col\n");
    input_size(&row, &col);
    printf("inpur matrix:\n");
    input_array(&row, &col, &matrix);
    transp_matrix(row, col, &matrix);
    output_array(row, col, matrix);


    input_later_instructions();
}

void array_allocate_memory(int* rows, int* cols, int*** array)
{
    (*array) = (int**)malloc(100 * sizeof(int*));
    for (int i = 0; i < (*rows); i++)
    {
        (*array)[i] = (int*)malloc(100 * sizeof(int));
    }
}

void input_size(int* row, int* col)
{
    while (scanf_s("%d", row) == 0 || (*row) <= 0 || getchar() != '\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
    while (scanf_s("%d", col) == 0 || (*col) <= 0 || getchar() != '\n')
    {
        printf("Wrong input");
        rewind(stdin);
    }
}

void input_array(int* row, int* col, int*** array)
{
    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *col; j++)
        {
            while (printf("elem[%d][%d] = ", i, j), scanf_s("%d", &(*array)[i][j]) == 0)
            {
                printf("Wrong input");
                rewind(stdin);
            }
        }
    }

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