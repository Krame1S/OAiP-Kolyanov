#include"funcs.h"

PC* structArrMemAlloc(int amountOfPCs)
{
	PC* temp = (PC*)malloc(amountOfPCs * sizeof(PC));
	return temp;
}

int firstSymbol(char* str)
{
	int c = str[0];
	return c;
}

void strSwap(PC** list, char* str1, char* str2, int index)
{
	PC buf;
	if (firstSymbol(str1) > firstSymbol(str2))
	{
		buf = (*list)[index];
		(*list)[index] = (*list)[index + 1];
		(*list)[index + 1] = buf;
	}
}

void swap(PC** list, int num1, int num2, int index)
{
	PC buf;
	if (num1 > num2)
	{
		buf = (*list)[index];
		(*list)[index] = (*list)[index + 1];
		(*list)[index + 1] = buf;
	}
}

void addPCInList(PC subPC, PC** list, int* amountOfPCs)
{
	(*amountOfPCs)++;
	if ((*list) == NULL)
	{
		(*list) = (PC*)malloc((*amountOfPCs) * sizeof(subPC));
	}
	else
	{
		(*list) = (PC*)realloc((*list), (*amountOfPCs) * sizeof(subPC));
	}
	(*list)[(*amountOfPCs) - 1] = subPC;
}

char* inputString()
{
	char* string = (char*)calloc(256, sizeof(char));
	gets_s(string, 255);
	int amountOfPCs = strlen(string);
	string = (char*)realloc(string, amountOfPCs + 1);
	return string;
}

int choiceMenuOption()
{
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice <= 0 || choice > 5 || getchar() != '\n')
	{
		printf("\nYou need to choose between 1 and 5: ");
		rewind(stdin);
	}
	return choice;
}

int choiceMemberSort()
{
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 5 || getchar() != '\n')
	{
		printf("\nYou need to choose between 1 and 5: ");
		rewind(stdin);
	}
	return choice;
}

int choiceMemberTwoPosSort()
{
	int choiceOne = 0, choiceTwo = 0, sortIndex = 0;
	printf("Choose the prioritized position of sort: \n1) Name\n2) Price\n3) RAM\n 4) SSD\nEnter: ");
	while (scanf_s("%d", &choiceOne) == 0 || choiceOne < 1 || choiceOne > 4 || getchar() != '\n')
	{
		printf("\nYou need to choose between 1 and 4: ");
		rewind(stdin);
	}
	switch (choiceOne)
	{
	case 1:
		printf("Choose the second position to sort by: \n1) Price\n2) RAM\n3) SSD\nEnter: ");
		while (scanf_s("%d", &choiceTwo) == 0 || choiceTwo < 1 || choiceTwo > 3 || getchar() != '\n')
		{
			printf("\nYou need to choose between 1 and 3: ");
			rewind(stdin);
		}
		switch (choiceTwo)
		{
		case 1:
			sortIndex = 1;
			return sortIndex;
		case 2:
			sortIndex = 2;
			return sortIndex;
		case 3:
			sortIndex = 3;
			return sortIndex;
		}
	case 2:
		printf("Choose the second position to sort by: \n1) Name\n2) RAM\n3) SSD\nEnter: ");
		while (scanf_s("%d", &choiceTwo) == 0 || choiceTwo < 1 || choiceTwo > 3 || getchar() != '\n')
		{
			printf("\nYou need to choose between 1 and 3: ");
			rewind(stdin);
		}
		switch (choiceTwo)
		{
		case 1:
			sortIndex = 4;
			return sortIndex;
		case 2:
			sortIndex = 5;
			return sortIndex;
		case 3:
			sortIndex = 6;
			return sortIndex;
		}
	case 3:
		printf("Choose the second position to sort by: \n1) Price\n2) Name\n3) SSD\nEnter: ");
		while (scanf_s("%d", &choiceTwo) == 0 || choiceTwo < 1 || choiceTwo > 3 || getchar() != '\n')
		{
			printf("\nYou need to choose between 1 and 3: ");
			rewind(stdin);
		}
		switch (choiceTwo)
		{
		case 1:
			sortIndex = 7;
			return sortIndex;
		case 2:
			sortIndex = 9;
			return sortIndex;
		case 3:
			sortIndex = 8;
			return sortIndex;
		}
	case 4:
		printf("Choose the second position to sort by: \n1) Price\n2) RAM\n3) Name\nEnter: ");
		while (scanf_s("%d", &choiceTwo) == 0 || choiceTwo < 1 || choiceTwo > 3 || getchar() != '\n')
		{
			printf("\nYou need to choose between 1 and 3: ");
			rewind(stdin);
		}
		switch (choiceTwo)
		{
		case 1:
			sortIndex = 10;
			return sortIndex;
		case 2:
			sortIndex = 11;
			return sortIndex;
		case 3:
			sortIndex = 12;
			return sortIndex;
		}
	}
	
}


int sortChoice()
{
	int choice = 0;
	while (scanf_s("%d", &choice) == 0 || choice < 1 || choice > 3 || getchar() != '\n')
	{
		printf("\nYou need to pick between 1 and 3: ");
		rewind(stdin);
	}
	return choice;
}

int inputDelPC(int* amountOfPCs)
{
	int k = 0;
	while (scanf_s("%d", &k) == 0 || k <= 0 || k > (*amountOfPCs) || getchar() != '\n')
	{
		printf("\nThis PC doesn't exist. Choose another one...\n");
		rewind(stdin);
	}
	return k;
}

int inputPrice()
{
	int price = 0;
	while (scanf_s("%d", &price) == 0 || getchar() != '\n')
	{
		printf("\nPick a correct price\n");
		rewind(stdin);
	}
	return price;
}

int inputSSD()
{
	int SSD = 0;
	while (scanf_s("%d", &SSD) == 0 || SSD < 128 || (SSD > 128 && SSD < 256) || (SSD > 256 && SSD < 512) || (SSD > 512 && SSD < 1024) || SSD > 1024 || getchar() != '\n')
	{
		printf("\nPick a correct SSD capacity\n");
		rewind(stdin);
	}
	return SSD;
}

int inputRAM()
{
	int RAM = 0;
	while (scanf_s("%d", &RAM) == 0 || RAM < 4 || (RAM > 4 && RAM < 8) || (RAM > 8 && RAM < 16) || RAM > 16 || getchar() != '\n')
	{
		printf("\nPick a correct RAM capacity (4, 8, 16)\n");
		rewind(stdin);
	}
	return RAM;
}

void printPCs(PC** list, int* amountOfPCs)
{
	for (int i = 0; i < (*amountOfPCs); i++)
	{
		printf("\nPC: \n");
		printf("%s\n", (*list)[i].name);
		printf("price: %d$\n", (*list)[i].price);
		printf("RAM: %dGB\n", (*list)[i].RAM);
		printf("SSD: %dGB\n", (*list)[i].SSD);
		printf("\n");
	}
}

int laterSortInstructionsChoice()
{
	int choice = 0;
	printf("1) Sort by second position\n2) Back to menu\nEnter: ");
	while (scanf_s("%d", &choice) == 0 || choice > 2 || choice < 1 || getchar() != '\n')
	{
		printf("\nWrong input");
		rewind(stdin);
	}
	return choice;
}

void sortPCs(PC** list, int* amountOfPCs)
{
	int choice = 0, check = 0;
	printf("\nChoice sort by:\n 1) name\n2) price\n3) SSD\n4) RAM\n");
	printf("Enter: ");
	choice = choiceMemberSort();
	switch (choice)
	{
	case 1:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				strSwap(list, (*list)[j].name, (*list)[j + 1].name, j);
			}
		}
		break;
	case 2:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				swap(list, (*list)[j].price, (*list)[j + 1].price, j);
			}
		}
		break;
	case 3:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				swap(list, (*list)[j].SSD, (*list)[j + 1].SSD, j);
			}
		}
		break;
	case 4:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				swap(list, (*list)[j].RAM, (*list)[j + 1].RAM, j);
			}
		}
		break;
	default:
		exit(0);
	}
}

void sortSecondPosition(PC** list, int* amountOfPCs)
{
	PC buf;
	int choice = 0;
	printf("Enter: ");
	choice = choiceMemberTwoPosSort();
	switch (choice)
	{
	case 1:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if ((firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)) || (firstSymbol((*list)[j].name) == firstSymbol((*list)[j + 1].name)) && ((*list)[j].price > (*list)[j + 1].price))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if ((firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)) || (firstSymbol((*list)[j].name) == firstSymbol((*list)[j + 1].name)) && ((*list)[j].RAM > (*list)[j + 1].RAM))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if ((firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)) || (firstSymbol((*list)[j].name) == firstSymbol((*list)[j + 1].name)) && ((*list)[j].SSD > (*list)[j + 1].SSD))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].price > (*list)[j + 1].price) || (*list)[j].price == (*list)[j + 1].price && (firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 5:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].price > (*list)[j + 1].price) || (*list)[j].price == (*list)[j + 1].price && ((*list)[j].RAM > (*list)[j + 1].RAM))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 6:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].price > (*list)[j + 1].price) || (*list)[j].price == (*list)[j + 1].price && ((*list)[j].SSD > (*list)[j + 1].SSD))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 7:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].RAM > (*list)[j + 1].RAM) || (*list)[j].RAM == (*list)[j + 1].RAM && ((*list)[j].price > (*list)[j + 1].price))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 8:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].RAM > (*list)[j + 1].RAM) || (*list)[j].RAM == (*list)[j + 1].RAM && ((*list)[j].SSD > (*list)[j + 1].SSD))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 9:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].RAM > (*list)[j + 1].RAM) || (*list)[j].RAM == (*list)[j + 1].RAM && (firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 10:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].SSD > (*list)[j + 1].SSD) || (*list)[j].SSD == (*list)[j + 1].SSD && ((*list)[j].price > (*list)[j + 1].price))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 11:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].SSD > (*list)[j + 1].SSD) || (*list)[j].SSD == (*list)[j + 1].SSD && ((*list)[j].RAM > (*list)[j + 1].RAM))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	case 12:
		for (int i = 0; i < (*amountOfPCs) - 1; i++)
		{
			for (int j = 0; j < (*amountOfPCs) - 1; j++)
			{
				if (((*list)[j].SSD > (*list)[j + 1].SSD) || (*list)[j].SSD == (*list)[j + 1].SSD && (firstSymbol((*list)[j].name) > firstSymbol((*list)[j + 1].name)))
				{
					buf = (*list)[j];
					(*list)[j] = (*list)[j + 1];
					(*list)[j + 1] = buf;
				}
			}
		}
		break;
	}
}

void sort(PC** list, int* amountOfPCs)
{
	if (*amountOfPCs == 0)
	{
		printf("You haven't added any PCs yet");
		menu(list, amountOfPCs);
	}
	int choice = 0;
	printf("\n");
	printf("How do you want to sort your list?\n");
	printf("1) Sort by one position\n");
	printf("2) Sort by two positions\n3) Back\n");
	printf("\n");
	printf("Enter: ");
	choice = sortChoice();
	switch (choice)
	{
	case 1:
		sortPCs(list, amountOfPCs);
		printPCs(list, amountOfPCs);
		break;
	case 2:
		sortSecondPosition(list, amountOfPCs);
		printPCs(list, amountOfPCs);
		break;
	default:
			menu(list, amountOfPCs);
	}
}

void delete(PC** list, int* amountOfPCs)
{
	if (*amountOfPCs == 0)
	{
		printf("You haven't added any PCs yet");
		menu(list, amountOfPCs);
	}
	int Pc = 0;
	printf("\n");
	if ((*amountOfPCs) > 1)
	{
		printf("Enter the number of PC you want to delete: ");
		Pc = inputDelPC(amountOfPCs);
	}
	if ((*amountOfPCs) == 1)
		Pc = 1;
	free((*list)[Pc -1].name);
	for (int i = (Pc - 1); i < (*amountOfPCs)-1; i++)
	{
		(*list)[i] = (*list)[i + 1];
	}
	(*amountOfPCs)--;
	(*list) = (PC*)realloc((*list), (*amountOfPCs) * sizeof(PC));
	printf("Deletion complited\n");
	printPCs(list, amountOfPCs);
}

void initPC(PC** list, int* amountOfPCs)
{
	PC temp;
	printf("\nLet's add new PC to the list!\n");
	printf("Enter name of a new PC: ");
	temp.name = inputString();
	printf("\nEnter price ($)");
	temp.price = inputPrice();
	printf("\nEnter RAM (GB): ");
	temp.RAM = inputRAM();
	printf("\nEnter SSD (GB)");
	temp.SSD = enumFunc(inputSSD());
	addPCInList(temp, list, amountOfPCs);
	printf("\n");
	printPCs(list, amountOfPCs);
}

int enumFunc(int num)
{
	if (num == 128) return LOW;
	if (num == 256) return NORMAL;
	if (num == 512) return HIGH;
	printf("Something went wrong. Sorry :((((((");
	return -1;
}

void menuPromt()
{
	printf("\nMENU\n");
	printf("1) View list\n");
	printf("2) Add PC to the list\n");
	printf("3) Delete PC from list\n");
	printf("4) Sort list\n");
	printf("5) Quit\n");
	printf("\n");
	printf("Enter: ");
}

void menu(PC** list, int* amountOfPCs)
{
	int choice = 0;
	menuPromt();
	choice = choiceMenuOption();
	switch (choice)
	{
	case 1:
		if ((*amountOfPCs) == 0)
			printf("You haven't added any PCs yet\n");
		printPCs(list, amountOfPCs);
		menu(list, amountOfPCs);
		break;
	case 2:
		initPC(list, amountOfPCs);
		menu(list, amountOfPCs);
		break;
	case 3:
		delete(list, amountOfPCs);
		menu(list, amountOfPCs);
		break;
	case 4:
		sort(list, amountOfPCs);
		menu(list, amountOfPCs);
		break;
	case 5:
		exit(2);
	default:
		exit(0);
	}
}