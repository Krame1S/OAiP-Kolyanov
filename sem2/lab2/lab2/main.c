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

int main() {
	
	tList* list = createNode(4, "frog");

	while (list != NULL) {
		printf("Word %s appears %d times in this file", list->word, list->num);
		list = list->next;
	}


	return 0;
}