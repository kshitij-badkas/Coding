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
	/*
	Demo(Demo &ref)
	{
		cout<<"Inside copy constructor.\n";
	}
	*/
	~Demo()	//destructor	
	{
		cout<<"\nInside destructor.\n";
		
		printf("Bye bye\n");

	}
	
};

int main(void)
{
	cout<<"Inside main() \n\n";
	{
		Demo obj1;
	}
	
	Demo obj2(11, 21);

	Demo obj3(51, 101);


	
	//Demo obj4(10);

	cout<<"Value of x in obj2 : "<<obj2.x<<"\n";
	cout<<"Value of y in obj2 : "<<obj2.y<<"\n";
	
	obj2.x++;
	cout<<"Value of x in obj2 : "<<obj2.x<<"\n";
	cout<<"Value of y in obj2 : "<<obj2.y<<"\n";
	
	cout<<"Value of x in obj3 : "<<obj3.x<<"\n";
	cout<<"Value of y in obj3 : "<<obj3.y<<"\n";
	
	cout<<"End of main() \n\n";
	
	
    return 0;
}
