#include <iostream>
using namespace std;

template <class T>

void Display(T A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << A[i] << endl;
    }
}

int main()
{
    int Arr[] = { 10, 20, 30, 40, 50 };
    Display(Arr, 5);

    float Brr[] = { 10.101, 20.201, 30.301, 40.401, 50.501 };
    Display(Brr, 5);

    return (0);
}
