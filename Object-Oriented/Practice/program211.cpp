#include <iostream>
using namespace std;

template <class T>

T Addition(T A, T B)
{
    T Ans = A + B;
    return (Ans);
}

int main()
{
    int No1 = 11, No2 = 21;
    int ret = 0;
    ret = Addition(No1, No2);
    cout << "Addition : " << ret << endl;

    float fNo1 = 11.11, fNo2 = 21.21;
    float fret = 0.0;
    fret = Addition(fNo1, fNo2);
    cout << "Addition : " << fret << endl;

    return (0);
}
