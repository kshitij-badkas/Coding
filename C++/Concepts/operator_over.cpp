#include<iostream>
using namespace std;

class Demo
{
	public:
		int x;
		int y;
		
		Demo(int i = 10, int j = 20)
		{
			x = i;
			y = j;
		}
};

int main(void)
{
	Demo obj1(11, 21);
	Demo obj2(51, 101);
	Demo robj(0,0);
	
	robj = obj1 + obj2;
	
    return 0;
}

