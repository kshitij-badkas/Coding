#include<iostream>
using namespace std;

class Demo
{
    // default access specifier -> private
        int i;
    
    public:
        int x;

    private:
        int y;

    public :
        Demo()
        {
            x = 10;
            y = 20;
            i = 30;
        }

        void fun(int no)
        {
            cout<<"Inside public fun: "<<no<<"\n";
            cout<<y<<"\n"; //allowed
            gun(1200); //allowed
        }

    private:
        void gun(int no)
        {
            cout<<"Inside private gun : "<<no<<"\n";
            cout<<y<<"\n"; //allowed

        }
};

int main()
{
    
    Demo obj;

    cout<<obj.x<<"\n"; //allowed
    //cout<<obj.y<<"\n"; //not allowed
    //cout<<obj.i<<"\n"; //not allowed

    obj.fun(10); //allowed
    //obj.gun(100); //not allowed

    return 0;
}