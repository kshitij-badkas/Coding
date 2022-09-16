#include<iostream>

using namespace std;

class Demo
{
	public: 
	
	//characteristics
	int x;
	int y;
	
	//behaviours
	
	Demo()	//default constructor
	{
		cout<<"Inside default constructor.\n";
		x = 0;
		y = 0;
	}
	
	Demo(int i, int j)	//parameterized constructor
	{
		cout<<"Inside parameterized constructor.\n";
		x = i;
		y = j;
	}
	
	Demo(Demo &ref)
	{
		cout<<"Inside copy constructor.\n";
	}

	~Demo()	//destructor	
	{
		cout<<"\nInside destructor.\n";
		
		printf("Bye bye\n");

	}
	
};

int main(void)
{
	int no = 11;
	int &x = no;
	int *p = &no;
		
    return 0;
}
