#include <iostream>
using namespace std;

class Number
{
    public:
    int Factorial(int iNo)
    {
        int iFact = 1, iCnt = 0;
        for(iCnt = 1; iCnt <= iNo; iCnt++)
        {
            // iFact = iFact * iCnt;
            iFact *= iCnt;          // shorthand assignment
        }

        return (iFact);
    }
};

int main()
{
    Number nobj;

    int iValue = 0, iRet = 0;

    cout << "Enter no : \n";
    cin >> iValue;

    iRet = nobj.Factorial(iValue);

    cout << "Factorial is : "<< iRet;

    return (0);
}
