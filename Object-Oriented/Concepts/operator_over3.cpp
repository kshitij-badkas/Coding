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

bool operator == (Demo op1, Demo op2)
{
	if((op1.x == op2.x) && (op1.y == op2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	Demo obj1(11, 21);
	Demo obj2(11, 21);
	Demo robj(0, 0);
	
	if(obj1 == obj2)	// ==(obj1, obj2);
	{
		cout << "Objects are same" << endl;
	}
	else 
	{
		cout << "Objects are different" << endl;
	}
	
	
    return 0;
}

