#include<iostream>
using namespace std;

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
		
		friend void fun();
};

// naked function
void fun()
{
	Demo obj1;
	cout << obj1.i << "\n";
	cout << obj1.j << "\n";
	cout << obj1.k << "\n";
}

int main()
{
	fun();
	return 0;
}

