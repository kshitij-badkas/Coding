#include<iostream>
using namespace std;

class Demo
{
    public:
        int i;
    private:
        int j;
    protected:
        int k;

    public:
        Demo()
        {
            i = 10;
            j = 20;
            k = 30;
        }


};
class Hello : public Demo
{
    public:
        int x;
    private:
        int y;
    protected:
        int z;
    
    public:
        Hello()
        {
            x = 100;
            y = 200;
            z = 300;
        }
    
        void fun()
        {
            cout<<"Insidee Hello fun()\n";
            cout<<k<<"\n";
        }
    
};
int main()
{    
    Demo dobj;
    cout<<dobj.i<<"\n";     // Allowed
    
    //dobj.j;     // NA
    //dobj.k;     // NA

    Hello hobj;
    cout<<hobj.x<<"\n";     // Allowed
    //hobj.y;     // NA
    //hobj.z;     // NA

    cout<<hobj.i<<"\n";     // Allowed
    
    //hobj.j;     // NA
    //hobj.k;     // NA

    hobj.fun();

    return 0;
}
