#include<iostream>

namespace Marvellous
{
	void fun(void)
	{
		std::cout << "Inside fun() \n";
	}
}
// no semicolon at the end because namespace is not a datatype.

int main(void)
{
	std::cout << "Jay Ganesh \n";
	
	// fun();
	Marvellous::fun();
	
	return 0;
}