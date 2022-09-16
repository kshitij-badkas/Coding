#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCLL
{
	private:
		PNODE Head;
		PNODE Tail;
		int CountNode;		//*

	public:
		DoublyCLL();
		void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
		int Count();
};
