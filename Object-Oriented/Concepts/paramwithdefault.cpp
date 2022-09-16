#include<iostream>
using namespace std;

class Demo
{
	public: 
		int i, j;		// instance variable (non-static)

		Demo(int a = 10, int b = 20)
		{
			this->i=a;
			this->j=b;
			cout<<this->i<<"\n";
			cout<<this->j<<"\n";
		}

		
};


int main(void)
{
	
	cout<<"Inside main()\n";

	Demo obj();

	//Demo obj1(11, 21);

	Demo obj2();

	

	return 0;
}

