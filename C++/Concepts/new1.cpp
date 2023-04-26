#include<iostream>

using namespace std;

class Demo
{
	public:
	int x;
	int y;
	
	Demo()
	{
		cout<<"Inside constructor\n";
	}
	
	~Demo()
	{
		cout<<"Inside destructor\n";
	}
	
	void fun()
	{
		cout<<"Inside fun()\n";
	}
	
};

int main(void)
{
	Demo obj; // Static object creation
	
	Demo *ptr = NULL;
	
	ptr = new Demo; // Dynamic object creation
	if(ptr == NULL)
	{
		cout<<" Unable to allocate\n";
	}
	else
	{
		cout<<"Jai Ganesh...\n"<<ptr<<"\n";

	}
	
	obj.fun();
	
	ptr->fun();
	
	//delete ptr;
	
    return 0;
}
