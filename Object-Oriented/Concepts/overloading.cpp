#include<iostream>
using namespace std;

class Demo
{
	public:
		int i, j;
		
		void fun() 		// Definition
		{
			cout<<"Inside fun()\n";
		}
		void fun(int no) // Overloaded Definition
		{
			cout<<"Inside fun(int no)\n";
		}
};

int main(void)
{
    return 0;
}

