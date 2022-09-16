#include<iostream>
using namespace std;

class Demo
{
	public:
		int i;
		const int j;
		
		Demo(int a, int b) : j(b)
		{
			i = a;
			cout << "Inside Demo() parameterized \n";
		}
		
		void fun()
		{
			cout << "Inside fun() \n";
			i++;		// allowed
			// j++; 	// not allowed
		}
		
		// b is a constant input argument
		void gun(int a, const int b) const 	// constant function / behaviour
		{
			int x = 10;
			const int y = 20;	// constant local variable
			
			cout << "Inside gun() \n";
			// i++;		// not allowed - i is characteristic
			// j++; 	// not allowed
			
			x++;		// allowed - x is local variable
			// y++;		// not allowed
			
			a++;		// allowed - a is local varaible as parameter
			// b++; 	// not allowed - b is a local constant variable as parameter 
		}
};

int main(void)
{
	
	Demo obj1(11, 21);
	const Demo obj2(11, 21); // constant object
	
	obj1.fun();
	obj1.gun(10, 20);
	
	// obj2.fun();		// not allowed 
	obj2.gun(10, 20);
	
	return 0;
}

