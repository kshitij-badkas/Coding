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

class Derived1 : public Derived
{
    public:
        int k, l;
        
        Derived1()
        {
            cout<<"Inside Derived1 constructor\n";
        }
        ~Derived1()
        {
            cout<<"Inside Derived1 ~destructor\n";
        }
};

int main()
{
    Derived1 dobj;

    cout<<"size of Base - "<<sizeof(Base)<<"\n";
    cout<<"size of Derived - "<<sizeof(Derived)<<"\n";
    cout<<"size of Derived1 - "<<sizeof(Derived1)<<"\n";

    return 0;
}
