#include<iostream>
using namespace std;

class Base //abstract class 
{
	public:
		int x, y;
		
		int Add(int a, int b) // concrete function
		{
			return a + b;
		}
		
		// pure virtual function
		virtual int Sub(int a, int b) = 0; // abstract function

};

class Derived: public Base
{
	public :
		int i, j;
		
		int Sub(int a, int b)
		{
			return a - b;
		}
		
		int Mult(int a, int b)
		{
			return a * b;
		}
};

int main()
{
	//Base bobj; // not allowed 
	Derived dobj;
	
	int ret = 0;
	Base *bp = new Derived();
    
	ret = bp->Add(11, 10);
	cout << ret <<" : Addition \n";
	
	ret = bp->Sub(11, 10);
	cout << ret <<" : Subtraction \n";
	
	//ret = bp->Mult(11, 10); // not allowed
	//cout << ret <<"\n";
	
	return 0;
}
