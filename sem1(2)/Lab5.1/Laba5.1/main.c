#include <stdio.h>
#include <stdlib.h>
#include "input_check.h"
#include "output.h"
#include "arrays.h"

int main()
{
    int ARR_SIZE;
    output_elem_amount();
    input_check_size(&ARR_SIZE);
    int *arr = malloc(sizeof(int) * 100);
    output_enter();
    input_check_arr(&ARR_SIZE, arr);   
    arrays_del_smaller_then_prew(&ARR_SIZE, &arr);
    output_array(&ARR_SIZE, &arr);
    free(arr);
    return 0;
}