#include<iostream>

namespace Marvellous
{
	void fun(void)
	{
		std::cout << "Inside fun() Marvellous \n";
	}
}
// no semicolon at the end because namespace is not a datatype.

namespace Infosystems
{
	void fun(void)
	{
		std::cout << "Inside fun() Infosystems \n";
	}
}
// no semicolon at the end because namespace is not a datatype.

int main(void)
{
	std::cout << "Jay Ganesh \n";
	
	using namespace Marvellous;
	using namespace Infosystems;
	
	// fun(); 	// ambiguity
	Infosystems::fun();
	
	return 0;
}
