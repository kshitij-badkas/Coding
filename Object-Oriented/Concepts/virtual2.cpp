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
	// dynamic memory
	Base *bp = new Base(); 		 // No casting
	Dervied *dp = new Dervied(); // No casting
	
	Base *bp1 = new Dervied();	 // Upcasting
	//Dervied *dp1 = new Base();	 // Downcasting - It is not allowed

    return 0;
}
