#include"input.h"

void input_string(char* argv, char** string)
{
    int i = 0;
    rewind(stdin);
    while (argv[i] != '\0')
    {
        (*string)[i++] = argv[i];
        (*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
    }
    (*string)[i] = '\0';
}