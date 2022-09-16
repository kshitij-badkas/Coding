#include<iostream>
using namespace std;

class Demo
{
	public:
		int i, j;
		
		void fun() 		// Definition
		{
			cout<<"Inside fun()\n";
		}
		void gun() 		// Definition
		{
			cout<<"Inside gun()\n";
		}
};

class Hello: public Demo
{
	public: 
		int x, y;
		
		void sun()
		{
			cout<<"Inside sun()\n";
		}
		
		void gun() 		// Re-definition
		{
			cout<<"Inside gun() of child\n";
		}
};

int main(void)
{
    return 0;
}

