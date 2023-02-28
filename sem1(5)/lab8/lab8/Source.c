#include <stdio.h>
#include <stdlib.h>
#include"input.h"
#include"arrays.h"
#include"sort.h"
#include"output.h"

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        printf("Error! You have not passed any arguments to the function.");
    }
    char** string;
    array_memory_allocate(argc, &string);
    for (int i = 1; i < argc; i++)
    {
        input_string(argv[i], &string[i]);
    }
    insert_sort(&string, argc);
    printf("\nSorted array of strings in descending order:\n");
    output_string(string, argc);
    free(string);
}