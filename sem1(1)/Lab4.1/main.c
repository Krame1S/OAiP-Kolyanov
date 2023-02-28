#include <stdio.h>
#include <stdlib.h>

void users_arr_input(int arr[100][100], int *rows, int *cols);
void random_arr_input(int arr[100][100], int *rows, int *cols);
void input_check(int *row, int *col);
int choice_input_check();
void find_col_with_null(int arr[100][100], int *rows, int *cols);

int main()
{
    int arr[100][100], ROWS, COLS, choice;
    input_check(&ROWS, &COLS);
    choice = choice_input_check();
    switch (choice)
	{
	case 0:
		users_arr_input(arr, &ROWS, &COLS);
		break;
	case 1:
		random_arr_input(arr, &ROWS, &COLS);
		break;
	default:
		return 0;
		break;
	}
    find_col_with_null(arr, &ROWS, &COLS);
    return 0;
}

void input_check(int *row, int *col)
{
	printf("Enter number of rows: \n");
	while (!scanf("%d", row) || (*row) > 100 || (*row) < 1 || getchar()!= '\n')
	{
		printf("Wrong input. Try again\n");
		rewind(stdin);
	}
	printf("Enter number of colons: \n");
	while (scanf("%d", col) == 0 || (*col) > 100 || (*col) < 1 || getchar()!= '\n')
	{
		printf("Wrong input. Try again:\n");
		rewind(stdin);
	}
}

int choice_input_check()
{
    int choice_input;
    printf("If you want to use random input type 1.\nIf you want to enter elements of the array by yourself type 0:\n");
    while (scanf("%d", &choice_input) == 0 || getchar()!= '\n' || (choice_input!=1 && choice_input!=0))
	{
		printf("Wrong input. Try again:\n");
		rewind(stdin);
	}

    return choice_input;
}

void users_arr_input(int arr[100][100], int *rows, int *cols)
{
    for(int i=0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
            printf("Enter element in the %d colon and the %d row:\n", i+1, j+1);
            while(scanf("%d", &arr[j][i]) == 0 || getchar()!= '\n')
            {
            printf("Wrong input. Try again:\n");
            rewind(stdin);
            }
        }
    }
    printf("This is initial matrix: \n");
    for(int i=0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
            printf("%d  ", arr[i][j]);

        }
        printf("\n");
    }
}

void random_arr_input(int arr[100][100], int *rows, int *cols)
{
    int sign;
    srand(time(NULL));
    for(int i=0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
        sign = rand();
        if(sign % 2 == 0)
        {
            arr[i][j] = rand() %5;
            arr[i][j] *= (-1);
        }

        else
        {
            arr[i][j] = rand() %5;
        }

        }
    }
     printf("This is initial matrix: \n");
    for(int i=0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
            printf("%3.1d  ", arr[i][j]);

        }
        printf("\n");
    }
}

void find_col_with_null(int arr[100][100], int *rows, int *cols)
{
    int counter = *cols;
    for(int j = 0; j < (*rows); j++)
    {
        for(int i = 0; i < (*cols); i++)
        {
            if(arr[j][i] == 0)
            {
                counter--;
                break;
            }
        }
    }
    printf("Amount of colons without zero element is %d", counter);
}





















