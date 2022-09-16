#include<iostream>
using namespace std;

class Hello
{
	public:
		void fun();
		void gun();
};

class Demo
{
	public:
		int i;
		
	protected:
		int j;
		
	private:
		int k;
		
	public:
		Demo()
		{
			i = 10;
			j = 20;
			k = 30;
		}
		
		//friend void Hello::fun();
		//friend void Hello::gun();
		
		friend class Hello;
};

void Hello::fun()
{
	Demo obj1;
	cout << obj1.i << "\n";
	cout << obj1.j << "\n";
	cout << obj1.k << "\n";
}

void Hello::gun()
{
	Demo obj1;
	cout << obj1.i << "\n";
	cout << obj1.j << "\n";
	cout << obj1.k << "\n";
}

int main()
{
	Hello hobj;
	
	hobj.fun();
	hobj.gun();
	
	return 0;
}

