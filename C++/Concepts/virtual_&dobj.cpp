#include<iostream>
using namespace std;

class Base
{
	public: 
		int x, y;
		
		virtual void gun() = 0;
		
		virtual void sun() = 0;
		
		virtual void run() //1000
		{
			cout << "Base run()\n";
		}
};

class Dervied: public Base
{
	public:
		int i, j;
		
		void sun() //7000
		{
			cout << "Dervied sun()\n";
		}

		void fun() //5000
		{
			cout << "Dervied fun()\n";
		}
		
		void gun() //6000
		{
			cout << "Dervied gun()\n";
		}
		
		virtual void mun() //8000
		{
			cout << "Dervied mun()\n";
		}
};

int main(void)
{
	Base *bp = NULL;

	Dervied dobj;
	bp = &dobj;

	//bp = new Dervied();
	
	bp->fun();      // Derived fun
    bp->gun();      // Derived gun
    bp->sun();      // Base sun
    bp->run();      // Base run
    bp->mun();  	// Error
	
	cout << "Size of Base " << sizeof(Base) << "\n";
	cout << "Size of Base " << sizeof(Dervied) << "\n";

    return 0;
}
