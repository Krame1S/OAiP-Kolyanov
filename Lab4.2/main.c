#include <stdio.h>
#include <stdlib.h>

void users_arr_input(int arr[100][100], int *rows, int *cols);
void random_arr_input(int arr[100][100], int *rows, int *cols);
void input_check(int *row, int *col);
int choice_input_check();
void find_pos_val_row(int arr[100][100], int *rows, int *cols);

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
    find_pos_val_row(arr, &ROWS, &COLS);
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
            printf("Enter element in the %d row and the %d colon:\n", i+1, j+1);
            while(scanf("%d", &arr[i][j]) == 0 || getchar()!= '\n')
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
    printf("\n");
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
            arr[i][j] = rand() %202 - 101;
            arr[i][j] *= (-1);
        }
        else
        {
            arr[i][j] = rand() %202 - 101;
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
    printf("\n");
}



void find_pos_val_row(int arr[100][100], int *rows, int *cols)
{
    int bufer;
    for(int i = 0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
            if(arr[i][j] > 0)
            {
                bufer = i;
                for(int r = 0; r < (*cols); r++)
                    arr[bufer - 1][r] *= (-1);
                    printf("Row number %d has at least one positive element\n", i+1);
                    break;
            }
        }
    }
    for(int i = 0; i < (*rows); i++)
    {
        for(int j = 0; j < (*cols); j++)
        {
            printf("%3.1d  ", arr[i][j]);
        }
        printf("\n");
    }
}

























