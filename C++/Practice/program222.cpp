#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

// we can't use typdef with template

template <class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void Display();
        int CountNode();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T value)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    
    newn->data = value;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T value)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    
    newn = new node<T>;
    
    newn->data = value;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        temp = Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements from Singly LL : " << endl;

    struct node<T> *temp = NULL;

    if(Head == NULL)
    {
        return;
    }

    temp = Head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return (Count);
}

int main()
{
    SinglyLL<int> obj1;
    obj1.InsertFirst(11);
    obj1.InsertLast(21);
    obj1.InsertLast(51);
    obj1.Display();
    int Cnt = obj1.CountNode();
    cout << "Count of Nodes : " << Cnt << endl;

    SinglyLL<float> obj2;
    obj2.InsertFirst(11.11);
    obj2.InsertLast(21.21);
    obj2.InsertLast(51.51);
    obj2.Display();
    int fCnt = obj2.CountNode();
    cout << "Count of Nodes : " << fCnt << endl;

    return (0);
}
