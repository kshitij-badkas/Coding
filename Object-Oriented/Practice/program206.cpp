#include <iostream>
using namespace std;

void SwapR(int &p, int &q)      // call by reference
{
    int temp;
    temp = p;
    p = q;
    q = temp;
}

int main()
{
    int No1 = 11, No2 = 21;

    cout << "Before swapping data is : " << No1 << " " << No2 << endl;

    SwapR(No1, No2);      // call by reference

    cout << "After swapping data is : " << No1 << " " << No2 << endl;

    return (0);
}
