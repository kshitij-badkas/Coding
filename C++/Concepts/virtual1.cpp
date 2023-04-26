#include<iostream>
using namespace std;

class Base
{
	public: 
		int x, y;
};

class Dervied: public Base
{
	public:
		int i, j;
};

int main(void)
{
	// static memory
	Base obj;
	Dervied dobj;
	
	// dynamic memory
	Base *bp = new Base();
	Dervied *dp = new Dervied();

    return 0;
}

