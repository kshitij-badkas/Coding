#include<iostream>
using namespace std;

class Base
{
	public: 
		int x, y;
		
		virtual void fun() //1000
		{
			cout << "Base fun()\n";
		}
		
		virtual void gun() //2000
		{
			cout << "Base gun()\n";
		}
		
		void sun() //3000
		{
			cout << "Base sun()\n";
		}
		
		private :
			virtual void run() //4000
			{
				cout << "Base run()\n";
			}
};

class Dervied: public Base
{
	public:
		int i, j;
		
		void fun() //5000
		{
			cout << "Dervied fun()\n";
		}
		
		virtual void gun() //6000
		{
			cout << "Dervied gun()\n";
		}
		
		void sun() //7000
		{
			cout << "Dervied sun()\n";
		}
		
		virtual void mun() //8000
		{
			cout << "Dervied mun()\n";
		}
};

int main(void)
{
	Base *bp = new Dervied();	 // Upcasting
	
	int *p = NULL;
	
	bp->fun();      // Derived fun
    bp->gun();      // Derived gun
    bp->sun();      // Base sun
    bp->run();      // Base run
    // bp->mun();  // Error
	
	cout << "Size of Base " << sizeof(Base) << "\n";
	cout << "Size of Base " << sizeof(Dervied) << "\n";
	
	cout << "Size of p " << sizeof(p) << "\n";
	
    return 0;
}
