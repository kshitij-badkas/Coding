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
	// Allocate memory for node
	// initialize that node

	// check whether LL is empty or not
	// if LL is empty then new node is the first node so update its address first pointer through head
	
	// if LL is not empty then store the address of first node in the 'next' pointer of our new node
	// update the first pointer through head

	PNODE newn = NULL;
	newn = (PNODE) malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;

	if(*head == NULL)
	{
		*head = newn;
	}
	else	
	{
		newn->next = *head;
		*head = newn;
	}
}

void InsertLast(PPNODE head, int no)
{
	// Allocate memory for node
	// initialize that node

	// check whether LL is empty or not
	// if LL is empty then new node is the first node so update its address first pointer through head
	
	// if LL is not empty then 
	// travel till last node of LL
	// store address of new node in the next pointer of last node

	PNODE newn = NULL;
	PNODE temp = NULL;

	newn = (PNODE) malloc(sizeof(NODE));

	newn->data = no;
	newn->next = NULL;

	if(*head == NULL)
	{
		*head = newn;
	}
	else	
	{
		temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void Display(PNODE head)
{
	printf("Elements from LL are : \n");
	while(head != NULL)
	{
		printf("| %d | -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int Count(PNODE head)
{
	int iCnt = 0;
	while(head != NULL)
	{
		iCnt++;
		head = head->next;
	}
	return (iCnt);
}

void DeleteFirst(PPNODE head)
{
	PNODE temp = NULL;
	if(*head == NULL)		// LL is empty
	{
		return;
	}
	else	
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}

void DeleteLast(PPNODE head)
{
	PNODE temp = NULL;

	if(*head == NULL)
	{
		return;
	}
	else if((*head)->next == NULL)		// use (*head) instead of *head
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		temp = *head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->next = NULL;
	}
}

void InsertAtPos(PPNODE head, int no, int pos)
{
	// if pos is invalid then return directly (< 1 or > 5)
	// if position is 1 then call InsertFirst()
	// if position is N+1 then call InsertLast()
	
	PNODE newn = NULL;
	PNODE temp = NULL;
	int size = 0, iCnt = 0;
	size = Count(*head);

	if((pos < 1) || (pos > (size+1)))
	{
		printf("Position in invalid \n");
		return;
	}
	if(pos == 1)
	{
		InsertFirst(head, no);
	}
	else if(pos == size + 1)
	{
		InsertLast(head, no);
	}
	else
	{
		newn = (PNODE) malloc(sizeof(NODE));
		newn->data = no;
		newn->next = NULL;

		temp = *head;
		for(iCnt = 1; iCnt < pos-1; iCnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

	}
}

void DeleteAtPos(PPNODE head, int pos)
{
	// if pos is invalid then return directly (< 1 or > 4)
	// if position is 1 then call DeleteFirst()
	// if position is N+1 then call DeleteLast()

	PNODE temp = NULL;
	PNODE tempdelete = NULL;

	int size = 0, iCnt = 0;
	size = Count(*head);

	if((pos < 1) || (pos > (size)))
	{
		printf("Position in invalid \n");
		return;
	}
	if(pos == 1)
	{
		DeleteFirst(head);
	}
	else if(pos == size)
	{
		DeleteLast(head);
	}
	else
	{
		temp = *head;
		for(iCnt = 1; iCnt < pos; iCnt++)
		{
			temp = temp->next;
		}
		tempdelete = temp->next;
		temp->next = temp->next->next;
		free(tempdelete);

	}
}

int main()
{
	PNODE first = NULL;
	int iRet = 0;

	InsertFirst(&first, 101);	// Call by address
	InsertFirst(&first, 51);
	InsertFirst(&first, 21);
	InsertFirst(&first, 11);

	InsertAtPos(&first, 75, 3);
	
	DeleteAtPos(&first, 3);

	Display(first);				// Call by value

	iRet = Count(first);
	printf(" COunt of Elements of LL is : %d \n", iRet);

	InsertFirst(&first, 1);
	
	Display(first);				// Call by value

	iRet = Count(first);
	printf(" COunt of Elements of LL is : %d \n", iRet);

	InsertLast(&first, 111);
	InsertLast(&first, 121);

	Display(first);				// Call by value

	iRet = Count(first);
	printf(" COunt of Elements of LL is : %d \n", iRet);

	DeleteFirst(&first);
	DeleteFirst(&first);

	Display(first);				// Call by value

	iRet = Count(first);
	printf(" COunt of Elements of LL is : %d \n", iRet);

	DeleteLast(&first);

	Display(first);				// Call by value

	iRet = Count(first);
	printf(" COunt of Elements of LL is : %d \n", iRet);

	return (0);
}
