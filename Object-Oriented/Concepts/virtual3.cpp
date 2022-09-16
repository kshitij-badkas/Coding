#include<iostream>
using namespace std;

class Base
{
	public: 
		int x, y;
		
		void fun()
		{
			cout << "Base fun()\n";
		}
		
		void gun()
		{
			cout << "Base gun()\n";
		}
};

class Dervied: public Base
{
	public:
		int i, j;
		
		void sun()
		{
			cout << "Dervied sun()\n";
		}
		
		void fun()
		{
			cout << "Dervied fun()\n";
		}
};

int main(void)
{
	Base *bp = new Dervied();	 // Upcasting
	
	bp->fun();
	bp->gun();
	//bp->sun();	// Not allowed
	
	cout << "Size of Base " << sizeof(Base) << "\n";
	cout << "Size of Base " << sizeof(Dervied) << "\n";
	
    return 0;
}
