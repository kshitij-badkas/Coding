#include <iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int Size;

        ArrayX(int value);
        ~ArrayX();
        void Accept();
        void Display();
        int Maximum();
};

ArrayX::ArrayX(int value)
{
    Size = value;
    Arr = new int[Size];
}

ArrayX::~ArrayX()
{
    delete [] Arr;
}

void ArrayX::Accept()
{
    cout << "Enter values : " << endl;
    for(int i = 0; i < Size; i++)
    {
        cin >> Arr[i];
    }
}

void ArrayX::Display()
{
    cout << "Values are : " << endl;
    for(int i = 0; i < Size; i++)
    {
        cout << Arr[i] << endl;
    }
}

int ArrayX::Maximum()
{
    int Max = Arr[0];
    for(int i = 0; i < Size; i++)
    {
        if(Arr[i] > Max)
        {
            Max = Arr[i];
        }
    }
    return (Max);
}

int main()
{
    /*
    ArrayX obj1(5);
    obj1.Accept();
    obj1.Display();
    int ret = obj1.Maximum();
    cout << "Maximum : " << ret << endl;
    */
    
    ArrayX *obj2 = new ArrayX(5);
    obj2->Accept();
    obj2->Display();
    int ret = obj2->Maximum();
    cout << "Maximum : " << ret << endl;

    return (0);
}
