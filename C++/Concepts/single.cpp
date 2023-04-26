#include<iostream>
using namespace std;

class Base
{
    public:
        int i,j;

        Base()
        {
            cout<<"Inside Base constructor\n";
        }
        ~Base()
        {
            cout<<"Inside Base ~destructor\n";
        }
        
};
class Derived : public Base
{
    public:
        int a, b, c;
        
        Derived()
        {
            cout<<"Inside Derived constructor\n";
        }
        ~Derived()
        {
            cout<<"Inside Derived ~destructor\n";
        }
};

int main()
{
    Derived dobj;

    cout<<"size of Base - "<<sizeof(Base)<<"\n";
    cout<<"size of Derived - "<<sizeof(Derived)<<"\n";

    return 0;
}
