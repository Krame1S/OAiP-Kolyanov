#include <stdio.h>
#include <stdlib.h>

void users_arr_input(int arr[], int SIZE);
void random_arr_input(int arr[], int SIZE);
int find_max_module_element(int arr[], int SIZE);
int find_specif_arr_sum(int arr[], int SIZE);
int input_check();
int choice_input_check();

int main()
{
    int arr[100], ARR_SIZE, choice;
    ARR_SIZE = input_check();
    choice = choice_input_check();
    switch (choice)
	{
	case 0:
		users_arr_input(arr, ARR_SIZE);
		break;
	case 1:
		random_arr_input(arr, ARR_SIZE);
		break;
	default:
		return 0;
		break;
	}
	printf("The sum of elements between the first positive and the second positive element is %d \n", find_specif_arr_sum(arr, ARR_SIZE));
    printf("Maximum module number is %d \n", find_max_module_element(arr, ARR_SIZE));
    return 0;
}

int input_check()
{
	int input;
	printf("Enter number of elements you want to use:\n");
	while (scanf("%d", &input) == 0)
	{
		printf("Wrong input.\n");
		scanf("%d", &input);
		rewind(stdin);
	}
	while (input > 100  || input <=0)
	{
		printf("You can only enter a number that lies between 1 and 100.\nEnter number of elements you want to use:\n");
		scanf("%d", &input);
		rewind(stdin);
	}
	return input;
}

int choice_input_check()
{
    int choice_input;
    printf("If you want to use random input type 1.\nIf you want to enter elements of the array by yourself type 0:\n");
    while (scanf("%d", &choice_input) == 0 || (choice_input!=1 &&  choice_input!=0))
	{
		printf("Wrong input.\n");
		rewind(stdin);
	}

    return choice_input;
}

void users_arr_input(int arr[], int SIZE)
{
    printf("Enter elements of the array:\n");
    for(int i=0; i < SIZE; i++)
    {
        while(scanf("%d", &arr[i]) == 0 || arr[i] <=0)
        {
            printf("Wrong input. Try again:\n");
            rewind(stdin);
        }
    }
}

void random_arr_input(int arr[], int SIZE)
{
    int sign;
    srand(time(NULL));
    for(int i=0; i < SIZE; i++)
    {
        sign = rand();
        if(sign % 2 == 0)
        {
            arr[i] = rand();
            arr[i] *= (-1);
        }
        else
            arr[i] = rand();
        printf("%d\n", arr[i]);
    }
}

int find_max_module_element(int arr[], int SIZE)
{
    int curr_max = 0;
    for(int i=0; i < SIZE; i++)
    {
        if(arr[i] < 0)
            arr[i] *= (-1);
        if(curr_max < arr[i])
            curr_max = arr[i];
    }
    return curr_max;
}

int find_specif_arr_sum(int arr[], int SIZE)
{
    int sum=0, positive1=0,  positive2=0, indicator1=0, indicator2=0;
    for(int i=0; i < SIZE; i++)
    {
        if(arr[i] > 0 && indicator1 == 0)
        {
            positive1 = i;
            indicator1 = 1;
        }
    }
    positive1++;
    for(int i = positive1; i < SIZE; i++)
    {
        if(arr[i] > 0 && indicator2 == 0)
        {
            positive2 = i;
            indicator2 = 1;
        }
    }
    for(int i = positive1; i < positive2; i++)
        sum += arr[i];
    return sum;
}
