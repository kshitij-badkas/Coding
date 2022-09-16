#include<iostream>
using namespace std;

int main(void)
{
	
	typedef int NUMBER;
	typedef char LETTER;
	
	NUMBER no = 11;
	LETTER ch = 'M';
	
	cout <<sizeof(no) << "\n";
	cout << no << "\n";
	
	cout <<sizeof(ch) << "\n";
	cout << ch << "\n";
	
	typedef const int * CPTR;
	
	CPTR p = &no;
	//p = &no;
	
	cout << *p << "\n";
	
    return 0;
}
