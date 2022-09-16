#include<iostream>
using namespace std;

class Demo
{
	public:
		int i, j;	// instance variables : non-static varaibles
		static int x;	// class variable : static variable

		Demo()
		{
			cout<<"Inside Default constructor\n";

			i = 10;
			j = 20;
			
		}
};

int Demo::x = 30;

int main(void)
{
	cout<<"Static characteristic : "<< Demo::x<<"\n";
	
	/*
	Demo obj1;
	Demo obj2;

	cout<<"Inside main() : "<<sizeof(obj1)<<" bytes\n";	
	cout<<"Inside main() : "<<sizeof(obj2)<<" bytes\n";	

	cout<<obj1.i<<"\n";
	cout<<obj2.i<<"\n";
	*/

	return 0;
}

