#include<iostream>
using namespace std;

class Base
{
	public: 
		int i, j;		// instance variable (non-static)
		static int k;	// class variable (static)

		Base()
		{
			i = 10;
			j = 20;
		}

		//void fun(Demo *this, int no)
		void fun()
		{
			cout<<"Base fun()\n";
		}

		
};

int Base::k = 11;

class Derived : public Base
{
	public: 
		int x, y;		// instance variable (non-static)

		Derived()
		{
			x = 50;
			y = 60;
		}

		void gun()
		{
			cout<<"Derived gun()\n";
		}

		
};


int main(void)
{
	Base bobj;
	Derived dobj;
	
	cout << sizeof(bobj) << "\n";
	cout << sizeof(dobj) << "\n";
	
	cout << bobj.i << "\n";
	cout << bobj.j << "\n";
	
	cout << dobj.i << "\n";
	cout << dobj.j << "\n";
	
	cout << bobj.k << "\n";
	cout << dobj.k << "\n";

	//cout << bobj.x << "\n";
	
	bobj.fun();
	dobj.fun();
	dobj.gun();
	
	return 0;
}

