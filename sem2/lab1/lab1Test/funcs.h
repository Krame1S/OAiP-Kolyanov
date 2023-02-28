#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum SSD {
    LOW = 128,
    NORMAL = 256,
    HIGH = 512
};

typedef struct
{
    char *name;
    int price,
        RAM,
        SSD;
} PC;

PC* structArrMemAlloc(int amountOfPCs);

void addPCInList(PC subPC, PC** list, int* amountOfPCs);

void sort(PC** list, int* amountOfPCs);

int firstSymbol(char* str);

int inputDelPC(int* amountOfPCs);

char* inputString();

int choiceMenuOption();

int choiceMemberSort();

int sortChoice();

int inputPrice();

int inputSSD();

int inputRAM();

void menuPromt();

void delete(PC** list, int* amountOfPCs);

void printPCs(PC** list, int* amountOfPCs);

void sortByOnePosition(PC** list, int* amountOfPCs);

void sortByTwoPosition(PC** list, int* amountOfPCs);

void sort(PC** list, int* amountOfPCs);

void init_new_list(PC** list, int* amountOfPCs);

void initPC(PC** list, int* amountOfPCs);

void menu(PC** list, int* amountOfPCs);

void strSwap(PC** list, char* str1, char* str2, int index);

void swap(PC** list, int num1, int num2, int index);