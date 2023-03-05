#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct sList {
	int num;
	char* word;

	struct sList* next;
}tList;

tList* createNode(int setNum, char* setWord);
void pushFront(tList** list, int setNum, char* setWord, int* nodesAmount);
void insert(tList** list, int setNum, char* setWord, int pos, int* nodesAmount);
void pushBack(tList** list, int setNum, char* setWord, int* nodesAmount);
void popFront(tList** list, int* nodesAmount);
void popBack(tList** list, int* nodesAmount);
void emplace(tList** list, int* nodesAmount, int delPos);
void memoryFree(tList* usedList);
void throwError();
void parseHeader();
