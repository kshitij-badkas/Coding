#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
// typedef struct node ** PPNODE;

class SinglyCLL 
{
	private:			// Characteristics
		PNODE Head;
		PNODE Tail;
	
	public:				// Behaviours
		SinglyCLL();
		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPosition(int no, int ipos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int no);
		void Display();
		int Count();
};

SinglyCLL::SinglyCLL()
{
	Head = NULL;
	Tail = NULL;
}

void SinglyCLL::InsertFirst(int no)
{
	PNODE newn = NULL;

	newn = new NODE;
	newn->data = no;
	newn->next = NULL;

	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		Head = newn;
		Tail = newn;
	}
	else									// if LL contains atleast one node
	{
		newn->next = Head;
		Head = newn;
	}
	Tail->next = Head;
}

void SinglyCLL::InsertLast(int no)
{
	PNODE newn = NULL;

	newn = new NODE;
	newn->data = no;
	newn->next = NULL;

	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		Head = newn;
		Tail = newn;
	}
	else									// if LL contains atleast one node
	{
		Tail->next = newn;
		Tail = newn;
	}
	Tail->next = Head;
}

void SinglyCLL::InsertAtPosition(int no, int ipos)
{
	int iSize = Count();

	if((ipos < 1) || (ipos > iSize + 1))
	{
		cout << "Invalid position \n";
		return;
	}

	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == iSize + 1)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = NULL;

		newn = new NODE;
		newn->data = no;
		newn->next = NULL;

		PNODE temp = Head;

		for(int iCnt = 1; iCnt < ipos-1 ; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
	}
}

void SinglyCLL::DeleteFirst()
{
	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		return;
	}
	else if(Head == Tail)		// if LL contains 1 node
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->next;
		delete Tail->next;

		Tail->next = Head;
	}
}

void SinglyCLL::DeleteLast()
{
	PNODE temp = Head;

	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		return;
	}
	else if(Head == Tail)		// if LL contains 1 node
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		while(temp->next != Tail)
		{
			temp = temp->next;
		}
		delete temp->next;	// or delete Tail
		Tail = temp;
		
		Tail->next = Head;
	}
}

void SinglyCLL::DeleteAtPosition(int ipos)
{
	int iSize = Count();

	if((ipos < 1) || (ipos > iSize))
	{
		cout << "Invalid position \n";
		return;
	}

	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp1 = Head;

		for(int iCnt = 1; iCnt < ipos-1 ; iCnt++)
		{
			temp1 = temp1->next;
		}

		PNODE temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;

	}
}

void SinglyCLL::Display()
{
	PNODE temp = Head;

	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		return;
	}

	do
	{
		cout << "|" << temp->data << "| -> ";
		temp = temp->next;
	} while(temp != Head);

	cout << endl;
}

int SinglyCLL::Count()
{
	PNODE temp = Head;
	int iCnt = 0;
	
	if((Head == NULL) && (Tail == NULL))	// if LL empty
	{
		return (0);
	}
	
	do
	{
		iCnt++;
		temp = temp->next;
	} while(temp != Head);
	
	return (iCnt);
}

int main()
{
	int iRet = 0;
	SinglyCLL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);
	obj.InsertLast(151);
	obj.InsertLast(201);
	
	obj.Display();
	iRet = obj.Count();
	cout << "Count is : " << iRet << endl;

	obj.InsertAtPosition(75, 4);

	// obj.DeleteFirst();
	// obj.DeleteLast();

	obj.Display();
	iRet = obj.Count();
	cout << "Count is : " << iRet << endl;

	obj.DeleteAtPosition(4);
	
	obj.Display();
	iRet = obj.Count();
	cout << "Count is : " << iRet << endl;

	return (0);
}
