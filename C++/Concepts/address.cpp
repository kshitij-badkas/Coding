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
	}
	
	void fun(int no)
	{
		cout<<"Inside fun\n";
	}
	
};

int main(void)
{
	Demo obj(11, 21);
	obj.fun(15);
	
	
	
    return 0;
}
