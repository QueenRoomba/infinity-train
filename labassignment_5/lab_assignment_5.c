#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {

	if (head == NULL) {
		return 0;
	}
	int nodeLen = 0;
	node *temp = malloc(sizeof(node));
	temp = head;
	while(temp != NULL) {
		nodeLen++;
		temp = temp->next;
	}
	return nodeLen;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {

	int len = length(head);

	char *letter =(char *) malloc((len+1) * sizeof(char));

	node *temp = malloc(sizeof(node));
	temp = head;
	int index = 0;

	while(index < len) {
		letter[index] = temp->letter;
		index++;
		temp = temp->next;
	}
	
	return letter;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {

	node *temp1;
	node *temp2 =(node *) malloc(sizeof(node));
	temp2->letter = c;
	temp2->next = NULL;

	if (*pHead == NULL) {
		*pHead = temp2;
	}
	else {
		temp1 = *pHead;
		while(temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp2;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {

	node* temp = *pHead;

    while (temp != NULL)
    {
        *pHead = temp->next;
        free(temp);
        temp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}