#include "funcs.h"

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

void insert(tList** list, int setNum, char* setWord, int pos, int* nodesAmount) {

	if ((*nodesAmount) < pos - 1) {
		printf("error\n");
		exit(1);
	}

	tList* newNode = createNode(setNum, setWord);

	tList* temp = (*list);
	for (int i = 0; i < (pos - 2); i++)
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

void popFront(tList** list, int* nodesAmount) {

	tList* garbage = (*list);
	(*list) = (*list)->next;
	free(garbage);

	(*nodesAmount)--;
}

void popBack(tList** list, int* nodesAmount) {

	tList* temp = (*list);
	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	free(temp->next);
	temp->next = NULL;

	(*nodesAmount)--;
}

void emplace(tList** list, int* nodesAmount, int delPos) {

	tList* temp = (*list);

	if (delPos == 1) {
		(*list) = (*list)->next;
		free(temp);

		return;
	}

	for (int i = 0; i < (delPos - 2); i++)
		temp = temp->next;

	tList* tempMember = temp->next;

	temp->next = tempMember->next;
	free(tempMember);

	(*nodesAmount)--;
}

void memoryFree(tList* usedList) {

	tList* temp;

	while (usedList) {
		temp = usedList;
		usedList = usedList->next;
		free(temp);
	}
}

void throwError() {

	printf("Error\n");

	fflush(stdin);
	exit(1);
}

void parseHeader() {

	FILE* fp, *dest;
	errno_t err;
	
	err = fopen_s(&fp, "C:\\work\\headerC.txt", "r");
	if (err != 0)
		throwError();

	err = fopen_s(&dest, "C:\\work\\headerH.txt", "w");
	if (err != 0)
		throwError();

	char* subString = ") {\n\n";

	char* buffer = malloc(2);
	if (buffer == NULL)
		throwError();

	char c;
	int i = 0;

	fseek(fp, 0, SEEK_SET);

	while (true) {
		int flag = 0;
		while ((c = fgetc(fp)) != '\n' && c != EOF && buffer != NULL) {
			buffer[i] = c;
			char* temp = realloc(buffer, sizeof(char) * ((long long)(i)+2));
			if (temp != NULL)
				buffer = temp;
			i++;
		}

		if (c == EOF) {
			printf("DONE WRITING TO THE HEADER FILE\n");
			break;
		}

		if (buffer != NULL && ((long long)(i)+1) > sizeof(buffer)) {
			buffer[i] = c;
			buffer[i + 1] = fgetc(fp);
		}

		if ( buffer != NULL && (strstr(buffer, subString)) != NULL) {
			flag = 1;
			char* temp = realloc(buffer, sizeof(char) * ((long long)(i) - 1));
			if (temp != NULL)
				buffer = temp;
			if (buffer != NULL) {
				buffer[i - 2] = ';';
				buffer[i - 1] = '\0';
			}

			fprintf(dest, "%s\n", buffer);
		}
		if (flag == 1) {
			char* temp = realloc(buffer, sizeof(char) * 1);
			if (temp != NULL)
				buffer = temp;
		}
		i = 0;
	}

	fclose(fp);
	fclose(dest);

}