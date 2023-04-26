#include<iostream>
using namespace std;

class Max
{
    public:
    // Characteristics
    int a;
    int b;

    // Behaviour

    Max(int A, int B)   // Parametrised Constructor
    {
        cout<<"Inside parametrised constructor\n";
        a = A;
        b = B;
    }

    ~Max()  // Destructor
    {
        cout<<"Inside Destructor\n";
    }

    void maxFun()
    {
		if (a == b)
		{
			cout<<"a = b\n";
		}
		else if( a < b)
		{
			cout<<"b is grewter thatn a\n";
		}
		else
		{
			cout<<"a is grewter thatn b\n";
		}
    }
};

int main()
{
    int iValue1 = 0, iValue2 = 0;

    cout<<"Enter first number\n";
    cin>>iValue1;

    cout<<"Enter second number\n";
    cin>>iValue2; 

    Max obj(iValue1, iValue2); // Parametrised constructor

    obj.maxFun();

    return 0;
}