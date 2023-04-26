#include <stdio.h>
#include <stdlib.h>

// structure declaration
struct node
{
	int data;			// 4 bytes
	struct node *next;	// 8 bytes
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
	NODE obj;

	PNODE ptr = (PNODE)malloc(sizeof(NODE));

	obj.data = 11;			// Direct accessing operator
	obj.next = NULL;

	ptr -> data = 11;		// Indirect accessing operator
	ptr -> next = NULL;
	
	return (0);
}
