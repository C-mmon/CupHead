#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node* next;
	int data;
};
void addNode(struct Node ** head, int dataToAdd, int pos)
{
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = dataToAdd;
	newNode->next = NULL;
	if(*head == NULL || pos==0)
	{
		newNode->next =*head;
		*head= newNode;
		return;
	}

	struct Node* temp = *head;
	for(int i=0; i< pos-1 && temp->next != NULL ;i++)
	{
		temp = temp->next;
	}

	//1->2->3
	newNode->next= temp->next;
	temp->next= newNode;

	return ;
}

//delete the node list
void deletelist(struct Node** head, int dataToDelete)
{
	//we can have many cases, deleting the first node itself,
	struct Node* storeTemp = NULL;
	
	while(*head && (*head)->data == dataToDelete)
	{
		storeTemp =  *head;
		*head=(*head)->next;
		free(storeTemp);
	}
	if (*head == NULL)
        return;
	struct Node* temp = (*head)->next;
	struct Node* prev = *head;
	while(temp != NULL)
	{
		if(temp->data ==dataToDelete)
		{
            storeTemp = temp;
            prev->next = temp->next;
            temp = temp->next; // Don't move prev
			free(storeTemp);
		}
		else
		{
		    prev= temp;
		    temp= temp->next;
		}
		
		
	}
}

void printList(struct Node* t)
{
	while(t != NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}
int main()
{
	struct Node* st = NULL;
	addNode(&st, 1,0);
	addNode(&st, 2,0);
	addNode(&st, 1,0);
	printList(st);

	deletelist(&st, 1);
	printf("deleted nodes");
	printList(st);


}
