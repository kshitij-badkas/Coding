#include<iostream>
using namespace std;

class Demo
{
	public: 
		int i, j;		// instance variable (non-static)
		static int x;	// class variable (static)

		Demo(int a = 10, int b = 20)
		{
			cout<<"Inside parameteried constructor with default args\n";
			
			this->i = a;
			this->j = b;
		}

		//void fun(Demo *this, int no)
		void fun(int no)
		{
			cout<<"Inside non-static fun()\n";
			cout<<this->i<<"\n";
			cout<<this->j<<"\n";
		}

		static void gun(int value)
		{
			cout<<"Inside static gun() : "<<value<<"\n";
			
			// cout<<this->i<<"\n";  //Error

		}
};

int Demo::x = 30;

int main(void)
{
	cout<<Demo::x<<"\n";
	Demo::gun(100);

	return 0;
}

