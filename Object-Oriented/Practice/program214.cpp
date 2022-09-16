#include <iostream>
using namespace std;

template <class T>

void DisplayMax(T A[], int size)
{
    T max = A[0];
    for(int i = 0; i < size; i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }
    }
    cout << max << endl;
}

int main()
{
    int Arr[] = { 10, 20, 30, 40, 50, 11, 22 };
    DisplayMax(Arr, 7);

    float Brr[] = { 10.101, 20.201, 30.301, 40.401, 50.501, 11.11, 22.22 };
    DisplayMax(Brr, 7);

    return (0);
}
