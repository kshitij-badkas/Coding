#include <iostream>
using namespace std;

class Number
{
    private:
        int iNo;
    
    public:
        void Accept()       // Setter
        {
            cout << "Enter value : \n";
            cin >> iNo;
        }

        void Display()      // Getter
        {
            cout << "Value is : "<< this->iNo << endl;
        }

        // Add function here with logic
};

int main()
{
    Number nobj1;


    nobj1.Accept();
    nobj1.Display();
    iRet = nobj1.Factorial();
    cout << "Factorial is : "<< iRet << endl;

    nobj2.Accept();
    nobj2.Display();
    iRet = nobj2.Factorial();
    cout << "Factorial is : "<< iRet << endl;

    return (0);
}
