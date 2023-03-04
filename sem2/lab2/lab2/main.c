#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

typedef struct sList {
	int num;
	char* word;

	struct sList *next;
}tList;

tList* createNode(int setNum, char* setWord) {

	tList* node = (tList*)malloc(sizeof(tList));

	if (node != NULL) {

		node->num = setNum;
		node->word = setWord;

		node->next = NULL;
	}

	return node;
}

void pushFront(tList** list, int setNum, char* setWord, int* nodesAmount) {

	tList* newNode = createNode(setNum, setWord);

	newNode->next = *list;
	*list = newNode;

	(*nodesAmount)++;
}

void pushInsert(tList** list, int setNum, char* setWord, int pos, int* nodesAmount) {

	if ((*nodesAmount) < pos-1) {
		printf("error\n");
		exit(1);
	}

	tList* newNode = createNode(setNum, setWord);

	tList* temp = (*list);
	for (int i = 0; i < (pos-2); i++)
		temp = temp->next;
	
	newNode->next = temp->next;
	temp->next = newNode;

	(*nodesAmount)++;
}

void pushBack(tList** list, int setNum, char* setWord, int* nodesAmount) {
	
	tList* newNode = createNode(setNum, setWord);

	tList* temp = (*list);

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

	(*nodesAmount)++;
}

void memoryFree(tList* usedList) {
	tList* temp;

	while (usedList) {
		temp = usedList;
		usedList = usedList->next;
		free(temp);
	}
}

int main() {
	
	int nodesAmount = 0;
	tList* list = createNode(4, "BASEfrog");

	pushFront(&list, 12, "front", &nodesAmount);
	pushBack(&list, 2, "back", &nodesAmount);
	pushInsert(&list, 44, "OOOOOOOOOOO", 3, &nodesAmount);

	while (list != NULL) {
		printf("Word %s appears %d times in this file\n", list->word, list->num);
		list = list->next;
	}	

	memoryFree(list);

	return 0;
}
