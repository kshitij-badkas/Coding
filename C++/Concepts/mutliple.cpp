#include<iostream>
using namespace std;

class Base1
{
    public:
        int i,j;

        Base1()
        {
            cout<<"Inside Base1 constructor\n";
        }
        ~Base1()
        {
            cout<<"Inside Base1 ~destructor\n";
        }
        
};

class Base2
{
    public:
        int x, y;
        
        Base2()
        {
            cout<<"Inside Base2 constructor\n";
        }
        ~Base2()
        {
            cout<<"Inside Base2 ~destructor\n";
        }
};

class Derived : public Base2, Base1
{
    public:
        int a;
        
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

    cout<<"size of Base1 - "<<sizeof(Base1)<<"\n";
    cout<<"size of Base2 - "<<sizeof(Base2)<<"\n";
    cout<<"size of Derived - "<<sizeof(Derived)<<"\n";

    return 0;
}
