#include<iostream>
using namespace std;

class Demo
{
	public:
		int i;
		const int j;
		
		Demo() : j(20)	// member initialization
		{
			i = 10;
			// j = 20;
		}
		
		Demo(int a, int b) : i(a), j(b)
		{
			cout << "Inside Demo() parameterized \n";
		}
};

int main(void)
{
	
	Demo obj(11, 21);
	cout << obj.i << "\n";
	cout << obj.j << "\n";
	
	// obj.j++; // not allowed
	obj.j + 1; // no error but value is not modified.
	//cout << obj.j << "\n";

	
	return 0;
}

