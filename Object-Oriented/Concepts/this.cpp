#include<iostream>

using namespace std;

class Demo
{
	public:
	int x;
	int y;
	
	Demo(int a = 10, int b = 20)
	{
		x = a;
		y = b;

		cout<<x<<"\n";
		cout<<y<<"\n";


	}
};

int main(void)
{
	Demo obj1;
	
	Demo obj2(11, 21);
	
    return 0;
}
