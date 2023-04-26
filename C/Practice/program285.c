#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

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

// Display **Singly** LL in Reverse Order !!! 
void Display(PNODE head)
{
    if(head != NULL)
    {
        Display(head->next);      // Head Recursion
        printf("| %d |-> ",head->data);
    }
}

int Count(PNODE head)
{
    static int iCnt = 0;

    if(head != NULL)
    {
        iCnt++;
        head = head -> next;
        Count(head);
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    PNODE first = NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    Display(first);

    iRet = Count(first);
    printf("Number of nodes are  : %d\n",iRet);

    return 0;
}