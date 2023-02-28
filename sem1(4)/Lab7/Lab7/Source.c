#include "Source.h"

int main()
{
	int (*task)(void) = NULL;
	int choice;
	printf("Welcome to the main menu of the 7th labaratory work!\nChoose the task you want to execute:\n1) Task 1\n2) Task 2\n3) Quit\n");
	input_choice(&choice);
	switch (choice) {
	case 1:
		task = task1;
		task();
		break;
	case 2:
		task = task2;
		task();
		break;
	case 3:
		return 0;
		break;
	}
	return 0;
}