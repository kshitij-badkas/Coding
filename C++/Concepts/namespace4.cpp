#include<iostream>

namespace 
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
	
	fun();

	return 0;
}
