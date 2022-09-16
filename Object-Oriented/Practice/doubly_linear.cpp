#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node *Next;
    struct node *Prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class Doubly_LL
{
    private:
        PNODE Head;

    public:
        Doubly_LL();
        ~Doubly_LL();

        BOOL InsertFirst(int);
        BOOL InsertLast(int);
        BOOL InsertAtPosition(int, int);
        inline void Display();
        inline int Count();
        BOOL DeleteFirst();
        BOOL DeleteLast();
        BOOL DeleteAtPosition(int);
};

Doubly_LL::Doubly_LL()
{
    Head = NULL;
}

Doubly_LL::~Doubly_LL()
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

BOOL Doubly_LL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;
    if(newn == NULL)
    {
        return (FALSE);
    }
    newn->Data = no;
    newn->Prev = NULL;
    newn->Next = NULL;
    
    if(Head != NULL)        // if LL enmpty
    {
        newn->Next = Head;
        Head->Prev = newn;
    }
    
    Head = newn;
    
    return (TRUE);
}

BOOL Doubly_LL::InsertLast(int no)
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
    newn->Prev = NULL;

    if(Head != NULL)    // if LL not empty
    {
        temp = Head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = newn;
        newn->Prev = temp;
    }
    else            // if LL is empty
    {
        Head = newn;
    }

    return (TRUE);

}

void Doubly_LL::Display()
{
    PNODE temp = Head;

    while(temp != NULL)
    {
        cout << temp->Data << " <=> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

int Doubly_LL::Count()
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

BOOL Doubly_LL::InsertAtPosition(int no, int pos)
{
    PNODE newn = NULL, temp = NULL;

    int iSize = 0;
    iSize = Count();

    if((Head == NULL) || (pos > iSize +1) || (pos <= 0))
    {
        return (FALSE);
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        if(newn == NULL)
        {
            return (FALSE);
        }
        newn->Data = no;
        newn->Prev = NULL;
        newn->Next = NULL;

        temp = Head;
        for(int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->Next;
        }
        newn->Prev = temp;
        newn->Next = temp->Next;
        temp->Next->Prev = newn;
        temp->Next = newn;

    }
    return (TRUE);
}

BOOL Doubly_LL::DeleteFirst()
{
    PNODE temp = NULL;

    temp = Head;
    if(Head != NULL)        // LL not empty
    {
        Head = Head->Next;
        Head->Prev = NULL;
        delete temp;
    }
    else
    {
        return (FALSE);     // LL empty
    }

    return (TRUE);
}

BOOL Doubly_LL::DeleteLast()
{
    PNODE temp = NULL;
    
    temp = Head;
    if(Head == NULL)          // LL empty 
    {
        return (FALSE);     
    }
    else if(Head->Next == NULL) // LL contains one node
    {
        Head = Head->Next;
        delete temp;
    }
    else                // LL contains mpre than 1 node
    {
        while(temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Prev->Next = NULL;
        temp->Prev = NULL;
        delete temp;
    }
    
    return (TRUE);
}

BOOL Doubly_LL::DeleteAtPosition(int pos)
{
    int iSize = 0;
    PNODE temp = NULL;

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
        temp = Head;
        for(int iCnt = 1; iCnt < pos; iCnt++)
        {
            temp = temp->Next;
        }
        temp->Prev->Next = temp->Next;
        temp->Next->Prev = temp->Prev;
        delete temp;
    }

    return (TRUE);
}

int main()
{
    int iChoice = 1;
    int iValue = 0, ipos = 0, iRet = 0;
    Doubly_LL obj1;
    Doubly_LL *obj2 = new Doubly_LL();

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
