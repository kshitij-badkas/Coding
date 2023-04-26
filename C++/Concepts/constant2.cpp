#include<iostream>
using namespace std;

class Demo
{
	public:
		int i;
		 // const int j = 20;	// allowed but not good programming practice
		const int j;
		
		Demo() : j(20)	// member initialization
		{
			i = 10;
			// j = 20; // not allowed
		}
};

int main(void)
{
	
	Demo obj;
	cout << obj.i << "\n"; 	// 10
	cout << obj.j << "\n"; 	// 20
	
	return 0;
}

