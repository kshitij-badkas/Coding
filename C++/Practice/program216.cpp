#include <iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int Size;

        ArrayX(int value)
        {
            Size = value;
            Arr = new int[Size];
        }

        ~ArrayX()
        {
            delete [] Arr;
        }

        void Accept()
        {
            cout << "Enter values : " << endl;
            for(int i = 0; i < Size; i++)
            {
                cin >> Arr[i];
            }
        }

        void Display()
        {
            cout << "Values are : " << endl;
            for(int i = 0; i < Size; i++)
            {
                cout << Arr[i] << endl;
            }
        }
};

int main()
{
    ArrayX obj1(5);
    obj1.Accept();
    obj1.Display();

    ArrayX *obj2 = new ArrayX(5);
    obj2->Accept();
    obj2->Display();

    return (0);
}
