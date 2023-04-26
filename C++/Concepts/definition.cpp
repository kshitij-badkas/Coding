#include<iostream>
using namespace std;

class Demo
{
	public:
		int i, j;
		
		void fun(int *p) 		// Definition
		{
			cout<<"First definition\n";
		}
		
		void fun(float *p) 		// Definition
		{
			cout<<"Second definition\n";
		}
		
		void fun(int no) 		// Definition
		{
			cout<<"Thrid definition\n";
		}
		void gun() 		// Definition
		{
			cout<<"Inside gun()\n";
		}
};

int main(void)
{
	Demo obj;
	
	int no = 11;
	float f = 3.14f;
	
	obj.fun(no);
	obj.fun(&no);
	obj.fun(&f);
	//obj.gun();
	
    return 0;
}

