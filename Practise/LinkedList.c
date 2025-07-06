#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int data;
} Node;

void printLinkedList(Node* head)
{
    Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int userInput = 0;
	scanf("%d", &userInput);

	Node* list;
	Node* head = NULL;
	int store = 0;

	for(int i = 0; i < userInput; i++)
	{
		scanf("%d", &store);
		if(i == 0)
		{
			list = malloc(sizeof(Node));
			list->data = store;
			list->next = NULL;
			head = list;
		}
		else
		{
			list->next = malloc(sizeof(Node));
			list = list->next;
			list->data = store;
			list->next = NULL;
		}
	}

	printLinkedList(head);

	// Insertion part
	int userIndex = 0;
	scanf("%d", &userIndex);
	Node* userIn = malloc(sizeof(Node));
	int userData;
	scanf("%d", &userData);
	userIn->data = userData;
	userIn->next = NULL;

	if(userIndex == 0)
	{
		userIn->next = head;
		head = userIn;
	}
	else if(userIndex >= userInput)
	{
		list->next = userIn;
	}
	else
	{
		Node* temp = head;
		int count = 0;
		while(temp != NULL && count < userIndex - 1)
		{
			temp = temp->next;
			count++;
		}
		userIn->next = temp->next;
		temp->next = userIn;
	}

	printLinkedList(head);

	return 0;
}
