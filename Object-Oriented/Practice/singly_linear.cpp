#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Singly_LL
{
    private:
        PNODE Head;

    public:
        Singly_LL();
        ~Singly_LL();

        BOOL InsertFirst(int);
        BOOL InsertLast(int);
        BOOL InsertAtPosition(int, int);
        inline void Display();
        inline int Count();
        BOOL DeleteFirst();
        BOOL DeleteLast();
        BOOL DeleteAtPosition(int);
};

Singly_LL::Singly_LL()
{
    Head = NULL;
}

Singly_LL::~Singly_LL()
{
    PNODE temp, Navigate;

    if(Head != NULL)
    {
        Navigate = Head;
        while(Navigate != NULL)
        {
            temp = Navigate->Next;
            delete Navigate;
            Navigate = temp;
        }
    }
}

BOOL Singly_LL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    if(newn == NULL)
    {
        return (FALSE);
    }

    newn->Data = no;
    newn->Next = NULL;

    if(Head != NULL)
    {
        newn->Next = Head;
    }    
    
    Head = newn;
    
    return (TRUE);
}

BOOL Singly_LL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;
    if(newn == NULL)
    {
        return (FALSE);
    }

    newn->Data = no;
    newn->Next = NULL;

    if(Head != NULL)
    {
        temp = Head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
    }
    else
    {
        Head = newn;
    }

    return (TRUE);

}

void Singly_LL::Display()
{
    PNODE temp = Head;

    while(temp != NULL)
    {
        cout << temp->Data << " -> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int Singly_LL::Count()
{
    PNODE temp = Head;
    int iCnt = 0;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->Next;
    }
    return (iCnt);
}

int Singly_LL::InsertAtPosition(int no, int pos)
{
    int iSize = 0;
    iSize = Count();

    if((Head == NULL) || (pos > iSize +1 ) || (pos <= 0))
    {
        return (FALSE);
    }

    if(pos == 1)
    {
        return (InsertFirst(no));
    }
    else if(pos == iSize +1)
    {
        return (InsertLast(no));
    }
    else
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;
        if(newn == NULL)
        {
            return (FALSE);
        }

        newn->Data = no;
        newn->Next = NULL;

        temp = Head;
        for(int i = 1; i < pos -1; i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;

        return (TRUE);
    }
}

BOOL Singly_LL::DeleteFirst()
{
    PNODE temp = NULL;

    temp = Head;
    if(Head != NULL)        // LL not empty
    {
        Head = Head->Next;
        delete temp;
    }
    else
    {
        return (FALSE);     // LL empty
    }

    return (TRUE);
}

BOOL Singly_LL::DeleteLast()
{
    PNODE temp1 = NULL, temp2 = NULL;
    
    temp1 = Head;
    if(Head == NULL)            // LL empty 
    {
        return (FALSE);     
    }
    else if(Head->Next == NULL) // LL contains one node
    {
        Head = Head->Next;
        delete temp1;
    }
    else                // LL contains mpre than 1 node
    {
        while(temp1->Next->Next != NULL)
        {
            temp1 = temp1->Next;
        }
        temp2 = temp1->Next;
        temp1->Next = NULL;
        delete temp2;
    }
    
    return (TRUE);
}

BOOL Singly_LL::DeleteAtPosition(int pos)
{
    int iSize = 0;
    PNODE temp1 = NULL, temp2 = NULL;

    iSize = Count();

    if((Head == NULL) || (pos > iSize) || (pos <= 0))
    {
        return (FALSE);
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        temp1 = Head;
        for(int i = 1; i < pos -1; i++)
        {
            temp1 = temp1->Next;
        }
        temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete temp2;
    }

    return (TRUE);
}

int main()
{
    int iChoice = 1;
    int iValue = 0, ipos = 0, iRet = 0;
    Singly_LL obj1;
    Singly_LL *obj2 = new Singly_LL();

    while(iChoice != 0)
    {
        cout << "Enter choice : " << endl;
        cout << "1. Insert First " << endl;
        cout << "2. Insert Last " << endl;
        cout << "3. Insert at Position " << endl;
        cout << "4. Delete First " << endl;
        cout << "5. Delete Last " << endl;
        cout << "6. Delete at Position " << endl;
        cout << "7. Display " << endl;
        cout << "8. Count " << endl;
        cout << "9. Terminate " << endl;

        cin >> iChoice;

        switch(iChoice)
        {
            case 1:
                cout << "Enter value to insert : " << endl;
                cin >> iValue;
                obj1.InsertFirst(iValue);
                break;

            case 2:
                cout << "Enter value to insert : " << endl;
                cin >> iValue;
                obj1.InsertLast(iValue);
                break;
            
            case 3:
                cout << "Enter value to insert : " << endl;
                cin >> iValue;
                cout << "Enter Position to insert : " << endl;
                cin >> ipos;
                obj1.InsertAtPosition(iValue, ipos);
                break;

            case 4: 
                obj1.DeleteFirst();
                break;

            case 5: 
                obj1.DeleteLast();
                break;

            case 6: 
                cout << "Enter Position to delete : " << endl;
                cin >> ipos;
                obj1.DeleteAtPosition(ipos);
                break;
            
            case 7:
                obj1.Display();
                break;

            case 8:
                iRet = obj1.Count();
                cout << "Number of elements : " << iRet << endl;
                break;

            case 9:
                cout << "Thank You for using the application" << endl;
                iChoice = 0;
                break;

            default :
                cout << "Please enter correct choice" << endl;
                break;
        } // end of switch
    } //end of while

    return (0);
}
