#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head, int no)
{
	printf("Inside InsertFirst - %d\n", no);

	// allocate memory
	PNODE newNode = NULL;
	newNode = (PNODE) malloc(sizeof(NODE));

	newNode->data = no;
	newNode->next = NULL;

	if(*head == NULL)		// LL empty
	{
		*head = newNode;
	}
	else
	{
		newNode->next = *head;
		*head = newNode;
	}
}

void InsertLast(PPNODE head, int no)
{
	printf("Inside InsertLast - %d\n", no);

	// allocate memory
	PNODE newNode = NULL;
	PNODE tempNode = NULL;
	newNode = (PNODE) malloc(sizeof(NODE));

	newNode->data = no;
	newNode->next = NULL;

	if(*head == NULL)		// LL empty
	{
		*head = newNode;
	}
	else
	{
		tempNode = *head;
		while(tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}
}



int Count(PNODE head)
{
	printf("Inside Count\n");

	int iCnt = 0;
	PNODE temp = head;

	while (temp != NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	
	return (iCnt);
}

void Display(PNODE head)
{
	printf("Inside Display\n");
	PNODE temp = head;

	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void InsertAtPos(PPNODE head, int no, int pos)
{
	int i = 0;
	int size = 0;
	
	size = Count(*head);
	
	PNODE temp = NULL;
	PNODE newNode = NULL;

	if((pos  < 0) || (pos > size + 1))
	{
		printf("Invalid Position\n");
	}
	else if(pos == 1)
	{
		InsertFirst(head, no);
	}
	else if(pos == size + 1)
	{
		InsertLast(head, no);
	}
	else
	{
		newNode = (PNODE) malloc(sizeof(NODE));
		newNode->data = no;

		temp = *head;
		
		for(i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;

	}
}

int main()
{
	int count = 0;
	PNODE first = NULL;

	InsertFirst(&first, 21);
	InsertFirst(&first, 11);
	InsertLast(&first, 51);
	InsertAtPos(&first, 101, 3);

	Display(first);


	count = Count(first);
	printf("No. of elements : %d\n", count);

	return (0);
}