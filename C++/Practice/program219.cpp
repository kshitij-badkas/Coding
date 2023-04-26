#include <iostream>
using namespace std;

template <class T>
class ArrayX
{
    private:
        T *Arr;
        int Size;

    public:
        ArrayX(int value);
        ~ArrayX();
        void Accept();
        void Display();
        T Maximum();
};

// return_type className :: functionName(params)
template <class T>
ArrayX<T>::ArrayX(int value)
{
    Size = value;
    Arr = new T[Size];
}

// return_type className :: functionName(params)
template <class T>
ArrayX<T>::~ArrayX()
{
    delete [] Arr;
}

// return_type className :: functionName(params)
template <class T>
void ArrayX<T>::Accept()
{
    cout << "Enter values : " << endl;
    for(int i = 0; i < Size; i++)
    {
        cin >> Arr[i];
    }
}

// return_type className :: functionName(params)
template <class T>
void ArrayX<T>::Display()
{
    cout << "Values are : " << endl;
    for(int i = 0; i < Size; i++)
    {
        cout << Arr[i] << endl;
    }
}

// return_type className :: functionName(params)
template <class T>
T ArrayX<T>::Maximum()
{
    T Max = Arr[0];
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
    
    ArrayX<int> obj1(5);
    obj1.Accept();
    obj1.Display();
    int ret = obj1.Maximum();
    cout << "Maximum : " << ret << endl;
    
    
    ArrayX<float> *obj2 = new ArrayX<float> (5);
    obj2->Accept();
    obj2->Display();
    float fret = obj2->Maximum();
    cout << "Maximum : " << fret << endl;

    return (0);
}
