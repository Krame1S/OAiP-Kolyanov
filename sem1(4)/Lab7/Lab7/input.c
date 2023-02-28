#include "input.h"

void input_choice(int* choice)
{
	while (scanf_s("%d", choice) == 0 || (*choice) > 3 || (*choice) < 1 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_k(int* k)
{
	while (scanf_s("%d", k) == 0 || (*k) <=0 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_C(char* C)
{
	while (scanf_s("%c", C, 1) == 0 || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
}

void input_string(char** string)
{
	int input;
	int i = 0;
	rewind(stdin);
	while ((input = getchar()) != EOF && input != '\n')
	{
		(*string)[i++] = input;
		(*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
	}
	(*string)[i] = '\0';
}

void input_later_instructions()
{
	printf("\n\n1) Back to menu\n2) Quit\n");
	int later_instructions;
	while (scanf_s("%d", &later_instructions) == 0 || (later_instructions < 1 && later_instructions > 2) || getchar() != '\n')
	{
		output_wrong_input();
		rewind(stdin);
	}
	if (later_instructions == 1)
		main();
	else
		return 0;
}