#include<iostream>

using namespace std;

int main(void)
{
	int no = 11;
	int &x = no;
	int &y = x; //reference to reference
		
    return 0;
}
