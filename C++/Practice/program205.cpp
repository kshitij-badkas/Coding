#include <iostream>
using namespace std;

void SwapA(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int No1 = 11, No2 = 21;

    cout << "Before swapping data is : " << No1 << " " << No2 << endl;

    SwapA(&No1, &No2);      // call by address

    cout << "After swapping data is : " << No1 << " " << No2 << endl;

    return (0);
}
